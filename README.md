
````markdown
# 🧊 Rubik's Cube Solver

A C++ project that implements various algorithms to solve a Rubik's Cube, including BFS, DFS, IDDFS, and IDA*. The solver supports multiple internal representations of the cube (1D array, 3D array, and Bitboard) and also uses **Pattern Databases (PDB)** for heuristic optimization.

---

## 🚀 Features

- Multiple cube representations: 3D, 1D, Bitboard
- Solvers implemented:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Iterative Deepening DFS (IDDFS)
  - Iterative Deepening A* (IDA\*)
- Pattern Database (PDB) generation and lookup
- Heuristic support using Corner Pattern DB
- Modular and extensible design

---

## 📁 Project Structure

```text
RubiksCubeSolve/
├── Databases/
│   └── CornerDB.text
├── Models/
│   ├── RubiksCube3darray.cpp
│   ├── RubiksCube1darray.cpp
│   ├── RubiksCubeBitboard.cpp
│   ├── genericRubiksCube.cpp
│   ├── genericRubiksCube.h
│   └── PatternDatabases/
│       ├── CornerDBMaker.cpp
│       ├── CornerDBMaker.h
│       ├── CornerPatternDatabase.cpp
│       ├── CornerPatternDatabase.h
│       ├── PatternDatabase.cpp
│       ├── PatternDatabase.h
│       ├── NibbleArray.cpp
│       ├── NibbleArray.h
│       ├── math.cpp
│       ├── math.h
│       └── PermutationIndexer.h
├── Solver/
│   ├── DFSSOLVER.h
│   ├── BFSSOLVER.h
│   ├── IDDFSSolver.h
│   └── IDAstarSOLVER.h
├── main.cpp
├── CMakeLists.txt
````

---

## ⚙️ Build Instructions

### ✅ Requirements

* C++17 or above
* `g++` or `clang++`
* CMake (optional)
* IDE like CLion or VSCode with CMake support

### 🛠️ Build (Using CLI)

```bash
mkdir build
cd build
cmake ..
make
./RubiksCubeSolve
```

Or open the folder in **CLion** and hit **Build + Run**.

---

## 📦 Usage

You can modify `main.cpp` to select the cube representation and solver you want to use:

```cpp
RubiksCubeBitboard cube;
IDAstarSolver<RubiksCubeBitboard> solver(cube);
auto solution = solver.solve();
```

---

## 📚 Algorithms Explained

* **BFS**: Explores all states level-by-level
* **DFS**: Dives deep first, then backtracks
* **IDDFS**: DFS with increasing depth limits
* **IDA\***: Combines DFS with a heuristic to prune unpromising paths efficiently

---
## 🧠 Credits

Built by [Aneesh Singh Rajoriya](https://github.com/asr-orzz)

Based on Rubik's Cube solving algorithms and academic resources.

---



