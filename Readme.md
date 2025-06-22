<div align="center">

# 🧩 Advanced Sudoku Solver

*A comprehensive Sudoku solver with multiple algorithms, performance analytics, and professional CLI*

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)]()

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Algorithms](#-algorithms) • [Contributing](#-contributing)

</div>

---

## 🌟 Overview

This project demonstrates advanced programming concepts through a feature-rich Sudoku solver implementation. Built with clean architecture and optimized algorithms, it serves as both a practical tool and an educational resource for algorithmic thinking.

## ✨ Features

<table>
<tr>
<td width="50%">

### 🔍 **Solving Algorithms**
- **Classic Backtracking** - Traditional recursive approach
- **Constraint Propagation** - MRV heuristic optimization
- **Performance Comparison** - Real-time analytics

</td>
<td width="50%">

### 💾 **File Operations**
- **Save/Load Puzzles** - Persistent storage support
- **Standard Format** - Easy sharing and import
- **Batch Processing** - Multiple puzzle handling

</td>
</tr>
<tr>
<td width="50%">

### 📊 **Analytics Dashboard**
- **Execution Metrics** - Time and call tracking
- **Algorithm Comparison** - Side-by-side performance
- **Statistics Export** - Data analysis support

</td>
<td width="50%">

### 🎯 **Puzzle Management**
- **Difficulty Levels** - Easy, Medium, Hard generation
- **Grid Validation** - Comprehensive error checking
- **Professional UI** - Clean terminal interface

</td>
</tr>
</table>

---

## 🚀 Installation

### Prerequisites
- **GCC Compiler** (or any C compiler)
- **Terminal/Command Prompt**
- **Git** (for cloning)

### Quick Setup

```bash
# Clone the repository
git clone https://github.com/Dhritikrishna123/Sudoku_solver.git
cd SUDOKU_SOLVER

# Compile the program
gcc -o sudoku_solver sudoku_solver.c -lm

# Run the solver
./sudoku_solver
```

### One-Line Installation
```bash
git clone https://github.com/Dhritikrishna123/Sudoku_solver.git && cd SUDOKU_SOLVER && gcc -o sudoku_solver sudoku_solver.c -lm && ./sudoku_solver
```

---

## 📖 Usage

### 🎮 Interactive Menu

| Option | Action | Description |
|:------:|--------|-------------|
| **1** | 📋 Display | Show current puzzle state |
| **2** | 🔄 Backtrack | Solve using classic algorithm |
| **3** | ⚡ Propagate | Solve using optimized algorithm |
| **4** | 🎲 Generate | Create new puzzle (Easy/Medium/Hard) |
| **5** | 📁 Load | Import puzzle from file |
| **6** | 💾 Save | Export current puzzle |
| **7** | ✅ Validate | Check grid validity |
| **8** | 🔄 Reset | Restore original state |
| **0** | 🚪 Exit | Quit program |

### 📄 File Format

Puzzles use a simple 9×9 grid format with space-separated integers. Empty cells are represented by `0`.

**Example: `puzzle.txt`**
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

---

## 🧠 Algorithms

### 🔄 Backtracking Algorithm
> **Classic recursive approach with exhaustive search**

- **Time Complexity:** O(9^(n×n)) worst case
- **Space Complexity:** O(n×n)
- **Best For:** Learning, simple puzzles
- **Strategy:** Try each possibility, backtrack on conflicts

### ⚡ Constraint Propagation with MRV
> **Advanced optimization using Minimum Remaining Values heuristic**

- **Optimization:** Choose cells with fewest possibilities first
- **Performance:** 3-8x faster than basic backtracking
- **Best For:** Complex puzzles, performance-critical applications
- **Strategy:** Smart cell selection reduces search space

### 📊 Performance Comparison

<div align="center">

| Algorithm | Avg. Calls | Avg. Time | Speedup | Use Case |
|-----------|:----------:|:---------:|:-------:|----------|
| **Backtracking** | ~50,000 | ~0.05s | 1x | 📚 Educational |
| **Constraint Propagation** | ~5,000 | ~0.01s | **5x** | 🚀 Production |

</div>

### 🏆 Benchmark Results

<div align="center">

| Difficulty | Backtracking | Constraint Propagation | **Improvement** |
|------------|:------------:|:---------------------:|:---------------:|
| Easy | 0.001s | 0.0005s | **2x faster** |
| Medium | 0.025s | 0.008s | **3x faster** |
| Hard | 0.150s | 0.035s | **4.3x faster** |
| Expert | 2.5s | 0.3s | **8.3x faster** |

*Benchmarked on Intel i5-13500H @ 2.2GHz*

</div>

---



### 📈 Core Data Structure

```c
typedef struct {
    int backtrack_calls;    // Number of recursive calls
    int cells_filled;       // Cells attempted to fill
    double solve_time;      // Execution time in seconds
    bool solved;           // Solution status
} SolveStats;
```

---

## 🎯 Example Output

```
$ ./sudoku_solver

🧩 Advanced Sudoku Solver
Select option 2 for backtracking...

⚡ Solving with Backtracking Algorithm...
✅ Puzzle solved successfully!

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
║            📊 SOLVING STATISTICS        ║
╠════════════════════════════════════════╣
║ Backtrack Calls:     2,847             ║
║ Cells Filled:        3,156             ║
║ Solve Time:          0.0234 seconds    ║
║ Status:              ✅ SUCCESS         ║
╚════════════════════════════════════════╝
```

---

## 🔧 Customization

### ➕ Adding New Algorithms

1. **Create solving function:**
```c
bool solve_with_new_algorithm(int grid[SIZE][SIZE], SolveStats* stats) {
    // Your algorithm implementation
    return true; // or false if unsolvable
}
```

2. **Add menu option** in `main()` function
3. **Update display** in `print_menu()`

### 🎚️ Adjusting Difficulty

Modify the `generate_puzzle()` function:

```c
// Customize removal counts
int easy_remove = 30;    // 30-35 cells removed
int medium_remove = 42;  // 40-45 cells removed  
int hard_remove = 52;    // 50-55 cells removed
```

---

## 🧪 Testing

### 🎯 Test Coverage
- ✅ Valid solvable puzzles
- ❌ Invalid puzzles (no solution)
- 🔄 Edge cases (nearly complete grids)
- ⚡ Performance benchmarks

### 🚀 Quick Test

```bash
# Create test puzzle
echo "5 3 0 0 7 0 0 0 0 6 0 0 1 9 5 0 0 0 0 9 8 0 0 0 0 6 0 8 0 0 0 6 0 0 0 3 4 0 0 8 0 3 0 0 1 7 0 0 0 2 0 0 0 6 0 6 0 0 0 0 2 8 0 0 0 0 4 1 9 0 0 5 0 0 0 0 8 0 0 7 9" > test_puzzle.txt

# Run solver
./sudoku_solver
# Select: 5 → "test_puzzle.txt" → 2 (solve)
```

---

## 🤝 Contributing

We welcome contributions! Here's how to get started:

### 🔄 Quick Start
1. **Fork** the repository
2. **Create** feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** changes (`git commit -m 'Add amazing feature'`)
4. **Push** to branch (`git push origin feature/amazing-feature`)
5. **Open** Pull Request

### 📋 Guidelines
- 🎨 Follow existing code style
- 📝 Add comments for complex algorithms
- 🧪 Include test cases for new features
- 📚 Update documentation as needed

### 💡 Ideas for Contributions
- 🎨 GUI implementation
- 🌐 Web interface
- 📱 Mobile app version
- 🧠 Additional solving algorithms
- 🎯 Puzzle difficulty analysis
- 📊 Enhanced statistics

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🎖️ Acknowledgments

- 🧠 **Algorithm Research** - Constraint satisfaction techniques
- 🎨 **UI Design** - Terminal-based game interfaces  
- ⚡ **Optimization** - Competitive programming techniques
- 📚 **Educational Resources** - Algorithm visualization concepts

---

## 📞 Contact & Support

<div align="center">

**Dhritikrishna Tripathi**

📧 [dhritikrishnat@gmail.com](mailto:dhritikrishnat@gmail.com)  
🔗 [GitHub Repository](https://github.com/Dhritikrishna123/Sudoku_solver)

---

### ⭐ **Found this helpful? Star the repository!**

*Your support helps others discover this project*

</div>

---

<div align="center">

**Built with ❤️ and lots of ☕**

*Happy Solving! 🧩*

</div>
```

I've significantly enhanced your README with:

**Visual Improvements:**
- Added badges and shields for professional appearance
- Used emojis strategically for better visual hierarchy
- Created centered sections for better focus
- Added dividers and spacing for improved readability

**Content Organization:**
- Restructured sections with better flow
- Added a features comparison table
- Enhanced the algorithm explanation section
- Improved benchmark presentation with clear tables

**Enhanced Sections:**
- More engaging overview and introduction
- Better structured installation instructions
- Clearer usage examples with visual formatting
- Expanded customization and testing sections
- Professional contact and acknowledgments section

**Technical Improvements:**
- Better code syntax highlighting
- Improved table formatting
- Enhanced performance metrics presentation
- Clearer architecture documentation

The README now has a more professional, engaging appearance while maintaining all the technical depth of the original!