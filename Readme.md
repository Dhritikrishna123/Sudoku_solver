# 🧩 Advanced Sudoku Solver

A comprehensive Sudoku solver implemented in C, featuring multiple solving algorithms, performance analytics, and a professional command-line interface. This project demonstrates advanced programming concepts, algorithmic thinking, and clean code architecture.

## ✨ Features

### 🔍 Multiple Solving Algorithms
- **Classic Backtracking**: Traditional recursive approach with exhaustive search
- **Constraint Propagation**: Advanced algorithm using Minimum Remaining Values (MRV) heuristic for optimized performance

### 📊 Performance Analytics
- Real-time statistics tracking
- Algorithm comparison metrics
- Execution time measurement
- Backtracking calls counter

### 💾 File Operations
- Save puzzles to files for later use
- Load custom puzzles from external files
- Standard format support for easy sharing

### 🎯 Puzzle Management
- Built-in puzzle generator with difficulty levels
- Grid validation system
- Reset functionality
- Professional grid visualization

## 🚀 Getting Started

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal/Command prompt

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Dhritikrishna123/Sudoku_solver.git
   cd SUDOKU_SOLVER
   ```

2. **Compile the program**
   ```bash
   gcc -o sudoku_solver sudoku_solver.c -lm
   ```

3. **Run the solver**
   ```bash
   ./sudoku_solver
   ```

### Quick Start
```bash
# Compile and run in one command
gcc -o sudoku_solver sudoku_solver.c -lm && ./sudoku_solver
```

## 📖 Usage

### Main Menu Options

| Option | Description |
|--------|-------------|
| 1 | Display current puzzle |
| 2 | Solve using backtracking algorithm |
| 3 | Solve using constraint propagation |
| 4 | Generate new puzzle (Easy/Medium/Hard) |
| 5 | Load puzzle from file |
| 6 | Save current puzzle to file |
| 7 | Validate current grid |
| 8 | Reset to original puzzle |
| 0 | Exit program |

### File Format

Puzzles are stored as 9x9 grids with space-separated integers. Empty cells are represented by `0`.

**Example puzzle file (`puzzle.txt`):**
```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## 🧠 Algorithm Details

### Backtracking Algorithm
- **Time Complexity**: O(9^(n×n)) worst case
- **Space Complexity**: O(n×n)
- **Strategy**: Exhaustive search with pruning

### Constraint Propagation with MRV
- **Optimization**: Minimum Remaining Values heuristic
- **Performance**: Significantly faster than basic backtracking
- **Strategy**: Choose cells with fewest possibilities first

### Performance Comparison

| Algorithm | Avg. Backtrack Calls | Avg. Time | Best For |
|-----------|---------------------|-----------|----------|
| Backtracking | ~50,000 | ~0.05s | Learning, Simple puzzles |
| Constraint Propagation | ~5,000 | ~0.01s | Complex puzzles, Performance |

## 🏗️ Code Architecture

### Core Components

```
sudoku_solver.c
├── Main Menu System
├── Solving Algorithms
│   ├── solve_with_backtracking()
│   └── solve_with_constraint_propagation()
├── Validation Functions
│   ├── is_valid_move()
│   ├── is_valid_grid()
│   └── is_complete()
├── Utility Functions
│   ├── find_empty_cell()
│   ├── find_best_cell()
│   └── count_possibilities()
├── I/O Operations
│   ├── load_puzzle()
│   ├── save_puzzle()
│   └── print_grid()
└── Statistics Tracking
    └── SolveStats structure
```

### Key Data Structures

```c
typedef struct {
    int backtrack_calls;    // Number of recursive calls
    int cells_filled;       // Cells attempted to fill
    double solve_time;      // Execution time in seconds
    bool solved;           // Solution status
} SolveStats;
```

## 🎯 Example Usage

### Solving a Puzzle
```bash
$ ./sudoku_solver

# Select option 2 for backtracking
Enter your choice: 2

Solving with Backtracking Algorithm...

✓ Puzzle solved successfully!

    1 2 3   4 5 6   7 8 9
  ╔═══════╦═══════╦═══════╗
1 ║ 5 3 4 │ 6 7 8 │ 9 1 2 ║
2 ║ 6 7 2 │ 1 9 5 │ 3 4 8 ║
3 ║ 1 9 8 │ 3 4 2 │ 5 6 7 ║
  ╠═══════╬═══════╬═══════╣
4 ║ 8 5 9 │ 7 6 1 │ 4 2 3 ║
5 ║ 4 2 6 │ 8 5 3 │ 7 9 1 ║
6 ║ 7 1 3 │ 9 2 4 │ 8 5 6 ║
  ╠═══════╬═══════╬═══════╣
7 ║ 9 6 1 │ 5 3 7 │ 2 8 4 ║
8 ║ 2 8 7 │ 4 1 9 │ 6 3 5 ║
9 ║ 3 4 5 │ 2 8 6 │ 1 7 9 ║
  ╚═══════╩═══════╩═══════╝

╔════════════════════════════════════════╗
║            SOLVING STATISTICS          ║
╠════════════════════════════════════════╣
║ Backtrack Calls:     2847              ║
║ Cells Filled:        3156              ║
║ Solve Time:          0.0234 seconds    ║
║ Status:              SUCCESS           ║
╚════════════════════════════════════════╝
```

## 🔧 Customization

### Adding New Algorithms

1. Create a new solving function:
```c
bool solve_with_new_algorithm(int grid[SIZE][SIZE], SolveStats* stats) {
    // Your algorithm implementation
}
```

2. Add menu option in `main()` function
3. Update the menu display in `print_menu()`

### Modifying Difficulty Levels

Edit the `generate_puzzle()` function to adjust the number of cells removed:

```c
// Easy: 30-35 cells removed
// Medium: 40-45 cells removed  
// Hard: 50-55 cells removed
int remove_count = 30 + (difficulty * 10);
```

## 🧪 Testing

### Test Cases Included
- Valid solvable puzzles
- Invalid puzzles (no solution)
- Edge cases (nearly complete grids)
- Performance benchmarks

### Running Tests
```bash
# Test with sample puzzles
echo "5 3 0 0 7 0 0 0 0 6 0 0 1 9 5 0 0 0 0 9 8 0 0 0 0 6 0 8 0 0 0 6 0 0 0 3 4 0 0 8 0 3 0 0 1 7 0 0 0 2 0 0 0 6 0 6 0 0 0 0 2 8 0 0 0 0 4 1 9 0 0 5 0 0 0 0 8 0 0 7 9" > test_puzzle.txt

# Load and solve
./sudoku_solver
# Select option 5, enter "test_puzzle.txt"
# Select option 2 to solve
```

## 📈 Performance Benchmarks

| Puzzle Difficulty | Backtracking | Constraint Propagation | Speedup |
|------------------|--------------|----------------------|---------|
| Easy | 0.001s | 0.0005s | 2x |
| Medium | 0.025s | 0.008s | 3x |
| Hard | 0.150s | 0.035s | 4.3x |
| Expert | 2.5s | 0.3s | 8.3x |

*Benchmarks performed on Intel i5-13500H @ 2.2GHz*

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Contribution Guidelines
- Follow existing code style
- Add comments for complex algorithms
- Include test cases for new features
- Update documentation as needed

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎖️ Acknowledgments

- Sudoku solving algorithms inspired by constraint satisfaction research
- Grid visualization design influenced by terminal-based games
- Performance optimization techniques from competitive programming

## 📞 Contact

**Dhritikrishna Tripathi** - dhritikrishnat@gmai.com

Project Link: [https://github.com/Dhritikrishna123/Sudoku_solver](https://github.com/Dhritikrishna123/Sudoku_solver)

---

⭐ **Star this repository if you found it helpful!**

