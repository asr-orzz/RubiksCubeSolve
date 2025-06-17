
```markdown
# 🧩 Rubik's Cube Solver in C++

A modular and high-performance 3x3 Rubik’s Cube solver in C++, supporting various cube representations, multiple solving strategies, and advanced heuristic optimization using pattern databases.

> 🔗 [GitHub Repo](https://github.com/asr-orzz/RubiksCubeSolve)

---

## 🚀 Features

- 🔁 **Cube Representations**:
  - `RubiksCube3dArray`
  - `RubiksCube1dArray`
  - `RubiksCubeBitboard`

- 🔍 **Solving Algorithms**:
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Iterative Deepening DFS (IDDFS)
  - Iterative Deepening A* (IDA\*) with heuristics

- 🧠 **Pattern Databases (PDB)**:
  - Corner Pattern Database using `CornerDBMaker` and `CornerPatternDatabase`
  - Efficient bit-level storage via `NibbleArray`

- 🧪 **Testing Utilities**:
  - Random cube scrambler
  - Cube equality/hash functions
  - Benchmark-ready structure

---

## 📂 Folder Structure

```

RubiksCubeSolve/
├── Databases/
│   └── CornerDB.text
│
├── Models/
│   ├── RubiksCube3darray.cpp
│   ├── RubiksCube1darray.cpp
│   ├── RubiksCubeBitboard.cpp
│   ├── genericRubiksCube.{cpp,h}
│   └── PatternDatabases/
│       ├── CornerDBMaker.{cpp,h}
│       ├── CornerPatternDatabase.{cpp,h}
│       ├── PatternDatabase.{cpp,h}
│       ├── NibbleArray.{cpp,h}
│       ├── math.{cpp,h}
│       └── PermutationIndexer.h
│
├── Solver/
│   ├── DFSSOLVER.h
│   ├── BFSSOLVER.h
│   ├── IDDFSSolver.h
│   └── IDAstarSOLVER.h
│
├── main.cpp
└── CMakeLists.txt

````

---

## 🛠️ Build Instructions

### ✅ Requirements

- C++17 compatible compiler
- CMake (if using CLion or manual build)

### 🔨 Build & Run

#### Option 1: Command Line

```bash
g++ -std=c++17 main.cpp -o RubiksSolver
./RubiksSolver
````

#### Option 2: CLion / CMake

* Open project in CLion
* Build and Run directly

---

## 📘 Example Workflow

### 1. Generate Corner Database (once):

```cpp
CornerDBMaker dbMaker("Databases/CornerDB.text", 0x99);
dbMaker.bfsAndStore();  // Save DB to file
```

### 2. Solve Cube with IDA\*

```cpp
RubiksCubeBitboard cube;
cube.randomShuffleColor(5);
IDAstarSolver<RubiksCubeBitboard, HashBitboard> solver(cube, "Databases/CornerDB.text");
auto moves = solver.solve();
```

---

## 🙋‍♂️ Author

**Aneesh Singh Rajoriya**
🚀 Full-stack & Systems Developer | 🚧 Building & Breaking
📌 Jaipur, India
🔗 [GitHub](https://github.com/asr-orzz) 

