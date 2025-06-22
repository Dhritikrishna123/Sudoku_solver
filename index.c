#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 9
#define EMPTY 0

// Statistics structure
typedef struct {
    int backtrack_calls;
    int cells_filled;
    double solve_time;
    bool solved;
} SolveStats;

// Function prototypes
bool solve_sudoku(int grid[SIZE][SIZE], SolveStats* stats);
bool solve_with_backtracking(int grid[SIZE][SIZE], SolveStats* stats);
bool solve_with_constraint_propagation(int grid[SIZE][SIZE], SolveStats* stats);
bool is_valid_move(int grid[SIZE][SIZE], int row, int col, int num);
bool find_empty_cell(int grid[SIZE][SIZE], int* row, int* col);
bool find_best_cell(int grid[SIZE][SIZE], int* row, int* col);
int count_possibilities(int grid[SIZE][SIZE], int row, int col);
void print_grid(int grid[SIZE][SIZE]);
void print_grid_with_highlight(int grid[SIZE][SIZE], int highlight_row, int highlight_col);
bool is_valid_grid(int grid[SIZE][SIZE]);
bool is_complete(int grid[SIZE][SIZE]);
void copy_grid(int src[SIZE][SIZE], int dest[SIZE][SIZE]);
void generate_puzzle(int grid[SIZE][SIZE], int difficulty);
bool load_puzzle(int grid[SIZE][SIZE], const char* filename);
bool save_puzzle(int grid[SIZE][SIZE], const char* filename);
void print_menu();
void print_stats(SolveStats* stats);

int main() {
    int grid[SIZE][SIZE];
    int original[SIZE][SIZE];
    SolveStats stats = {0, 0, 0.0, false};
    int choice;
    char filename[100];
    
    // Default puzzle (medium difficulty)
    int default_puzzle[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    copy_grid(default_puzzle, grid);
    copy_grid(default_puzzle, original);
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║        ADVANCED SUDOKU SOLVER          ║\n");
    printf("║         Portfolio Project              ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nCurrent Puzzle:\n");
                print_grid(grid);
                break;
                
            case 2:
                printf("\nSolving with Backtracking Algorithm...\n");
                copy_grid(original, grid);
                stats = (SolveStats){0, 0, 0.0, false};
                
                clock_t start = clock();
                if (solve_with_backtracking(grid, &stats)) {
                    clock_t end = clock();
                    stats.solve_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                    stats.solved = true;
                    printf("\n✓ Puzzle solved successfully!\n");
                    print_grid(grid);
                    print_stats(&stats);
                } else {
                    printf("\n✗ No solution exists for this puzzle.\n");
                }
                break;
                
            case 3:
                printf("\nSolving with Constraint Propagation...\n");
                copy_grid(original, grid);
                stats = (SolveStats){0, 0, 0.0, false};
                
                start = clock();
                if (solve_with_constraint_propagation(grid, &stats)) {
                    clock_t end = clock();
                    stats.solve_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                    stats.solved = true;
                    printf("\n✓ Puzzle solved successfully!\n");
                    print_grid(grid);
                    print_stats(&stats);
                } else {
                    printf("\n✗ No solution exists for this puzzle.\n");
                }
                break;
                
            case 4:
                printf("Enter difficulty (1-Easy, 2-Medium, 3-Hard): ");
                int difficulty;
                scanf("%d", &difficulty);
                if (difficulty < 1 || difficulty > 3) difficulty = 2;
                
                generate_puzzle(grid, difficulty);
                copy_grid(grid, original);
                printf("\nNew puzzle generated!\n");
                print_grid(grid);
                break;
                
            case 5:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                if (load_puzzle(grid, filename)) {
                    copy_grid(grid, original);
                    printf("Puzzle loaded successfully!\n");
                    print_grid(grid);
                } else {
                    printf("Error loading puzzle from file.\n");
                }
                break;
                
            case 6:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                if (save_puzzle(grid, filename)) {
                    printf("Puzzle saved successfully!\n");
                } else {
                    printf("Error saving puzzle to file.\n");
                }
                break;
                
            case 7:
                if (is_valid_grid(grid)) {
                    printf("✓ Current grid is valid.\n");
                } else {
                    printf("✗ Current grid contains errors.\n");
                }
                break;
                
            case 8:
                copy_grid(original, grid);
                printf("Puzzle reset to original state.\n");
                print_grid(grid);
                break;
                
            case 0:
                printf("\nThank you for using the Sudoku Solver!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}

// Main solving function with algorithm selection
bool solve_sudoku(int grid[SIZE][SIZE], SolveStats* stats) {
    return solve_with_backtracking(grid, stats);
}

// Classic backtracking algorithm
bool solve_with_backtracking(int grid[SIZE][SIZE], SolveStats* stats) {
    stats->backtrack_calls++;
    
    int row, col;
    if (!find_empty_cell(grid, &row, &col)) {
        return true; // Puzzle solved
    }
    
    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(grid, row, col, num)) {
            grid[row][col] = num;
            stats->cells_filled++;
            
            if (solve_with_backtracking(grid, stats)) {
                return true;
            }
            
            grid[row][col] = EMPTY; // Backtrack
        }
    }
    
    return false;
}

// Advanced algorithm with constraint propagation
bool solve_with_constraint_propagation(int grid[SIZE][SIZE], SolveStats* stats) {
    stats->backtrack_calls++;
    
    int row, col;
    if (!find_best_cell(grid, &row, &col)) {
        return true; // Puzzle solved
    }
    
    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(grid, row, col, num)) {
            grid[row][col] = num;
            stats->cells_filled++;
            
            if (solve_with_constraint_propagation(grid, stats)) {
                return true;
            }
            
            grid[row][col] = EMPTY; // Backtrack
        }
    }
    
    return false;
}

// Check if placing num at (row, col) is valid
bool is_valid_move(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) return false;
    }
    
    // Check column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) return false;
    }
    
    // Check 3x3 box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + start_row][j + start_col] == num) return false;
        }
    }
    
    return true;
}

// Find first empty cell
bool find_empty_cell(int grid[SIZE][SIZE], int* row, int* col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == EMPTY) return true;
        }
    }
    return false;
}

// Find empty cell with minimum possibilities (MRV heuristic)
bool find_best_cell(int grid[SIZE][SIZE], int* row, int* col) {
    int min_possibilities = 10;
    bool found = false;
    
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (grid[r][c] == EMPTY) {
                int possibilities = count_possibilities(grid, r, c);
                if (possibilities < min_possibilities) {
                    min_possibilities = possibilities;
                    *row = r;
                    *col = c;
                    found = true;
                }
            }
        }
    }
    
    return found;
}

// Count valid numbers for a cell
int count_possibilities(int grid[SIZE][SIZE], int row, int col) {
    int count = 0;
    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(grid, row, col, num)) {
            count++;
        }
    }
    return count;
}

// Print the grid with formatting
void print_grid(int grid[SIZE][SIZE]) {
    printf("\n    1 2 3   4 5 6   7 8 9\n");
    printf("  ╔═══════╦═══════╦═══════╗\n");
    
    for (int row = 0; row < SIZE; row++) {
        if (row == 3 || row == 6) {
            printf("  ╠═══════╬═══════╬═══════╣\n");
        }
        
        printf("%d ║", row + 1);
        for (int col = 0; col < SIZE; col++) {
            if (col == 3 || col == 6) {
                printf("│");
            }
            
            if (grid[row][col] == EMPTY) {
                printf(" .");
            } else {
                printf(" %d", grid[row][col]);
            }
            
            if (col == 2 || col == 5 || col == 8) {
                printf(" ");
            }
        }
        printf("║\n");
    }
    
    printf("  ╚═══════╩═══════╩═══════╝\n");
}

// Print grid with highlighted cell
void print_grid_with_highlight(int grid[SIZE][SIZE], int highlight_row, int highlight_col) {
    printf("\n    1 2 3   4 5 6   7 8 9\n");
    printf("  ╔═══════╦═══════╦═══════╗\n");
    
    for (int row = 0; row < SIZE; row++) {
        if (row == 3 || row == 6) {
            printf("  ╠═══════╬═══════╬═══════╣\n");
        }
        
        printf("%d ║", row + 1);
        for (int col = 0; col < SIZE; col++) {
            if (col == 3 || col == 6) {
                printf("│");
            }
            
            if (row == highlight_row && col == highlight_col) {
                printf("[");
            } else {
                printf(" ");
            }
            
            if (grid[row][col] == EMPTY) {
                printf(".");
            } else {
                printf("%d", grid[row][col]);
            }
            
            if (row == highlight_row && col == highlight_col) {
                printf("]");
            } else if (col == 2 || col == 5 || col == 8) {
                printf(" ");
            }
        }
        printf("║\n");
    }
    
    printf("  ╚═══════╩═══════╩═══════╝\n");
}

// Validate entire grid
bool is_valid_grid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] != EMPTY) {
                int temp = grid[row][col];
                grid[row][col] = EMPTY;
                if (!is_valid_move(grid, row, col, temp)) {
                    grid[row][col] = temp;
                    return false;
                }
                grid[row][col] = temp;
            }
        }
    }
    return true;
}

// Check if puzzle is complete
bool is_complete(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == EMPTY) return false;
        }
    }
    return true;
}

// Copy grid
void copy_grid(int src[SIZE][SIZE], int dest[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            dest[row][col] = src[row][col];
        }
    }
}

// Generate a new puzzle (simplified)
void generate_puzzle(int grid[SIZE][SIZE], int difficulty) {
    // Clear grid
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            grid[row][col] = EMPTY;
        }
    }
    
    // Fill diagonal 3x3 boxes
    srand(time(NULL));
    for (int box = 0; box < 3; box++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                int num, attempts = 0;
                do {
                    num = (rand() % 9) + 1;
                    attempts++;
                } while (!is_valid_move(grid, box * 3 + row, box * 3 + col, num) && attempts < 50);
                
                if (attempts < 50) {
                    grid[box * 3 + row][box * 3 + col] = num;
                }
            }
        }
    }
    
    // Remove numbers based on difficulty
    int remove_count = 30 + (difficulty * 10);
    for (int i = 0; i < remove_count; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        grid[row][col] = EMPTY;
    }
}

// Load puzzle from file
bool load_puzzle(int grid[SIZE][SIZE], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return false;
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (fscanf(file, "%d", &grid[row][col]) != 1) {
                fclose(file);
                return false;
            }
        }
    }
    
    fclose(file);
    return true;
}

// Save puzzle to file
bool save_puzzle(int grid[SIZE][SIZE], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) return false;
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            fprintf(file, "%d ", grid[row][col]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    return true;
}

// Print main menu
void print_menu() {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║               MAIN MENU                ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ 1. Display Current Puzzle             ║\n");
    printf("║ 2. Solve with Backtracking            ║\n");
    printf("║ 3. Solve with Constraint Propagation  ║\n");
    printf("║ 4. Generate New Puzzle                ║\n");
    printf("║ 5. Load Puzzle from File              ║\n");
    printf("║ 6. Save Puzzle to File                ║\n");
    printf("║ 7. Validate Current Grid              ║\n");
    printf("║ 8. Reset to Original                  ║\n");
    printf("║ 0. Exit                               ║\n");
    printf("╚════════════════════════════════════════╝\n");
}

// Print solving statistics
void print_stats(SolveStats* stats) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║            SOLVING STATISTICS          ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Backtrack Calls: %8d           ║\n", stats->backtrack_calls);
    printf("║ Cells Filled:    %8d           ║\n", stats->cells_filled);
    printf("║ Solve Time:      %8.4f seconds   ║\n", stats->solve_time);
    printf("║ Status:          %s             ║\n", stats->solved ? "SUCCESS" : "FAILED ");
    printf("╚════════════════════════════════════════╝\n");
}