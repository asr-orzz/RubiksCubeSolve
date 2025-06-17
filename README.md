

```markdown
# 🧩 Rubik's Cube Solver in C++

A modular and efficient C++ Rubik's Cube solver that supports multiple solving algorithms and cube representations. Includes IDA*, BFS, DFS, IDDFS algorithms and an optimized heuristic using a pattern database (PDB).

---

## 🚀 Features

- 🧱 Multiple cube models:
  - 3D Array (`RubiksCube3dArray`)
  - 1D Array (`RubiksCube1dArray`)
  - Bitboard (`RubiksCubeBitboard`)

- 🧠 Solvers implemented:
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Iterative Deepening DFS (IDDFS)
  - IDA* Search (with corner pattern database)

- 💾 Pattern Databases:
  - Efficient `CornerPatternDatabase`
  - File-based persistent DB generation with `CornerDBMaker`
  - `NibbleArray` for compact storage

---

## 🗂️ Project Structure

```

RubiksCubeSolve/
├── Databases/
│   └── CornerDB.text
├── Models/
│   ├── RubiksCube3darray.cpp
│   ├── RubiksCube1darray.cpp
│   ├── RubiksCubeBitboard.cpp
│   ├── genericRubiksCube.cpp / .h
│   └── PatternDatabases/
│       ├── CornerDBMaker.cpp / .h
│       ├── CornerPatternDatabase.cpp / .h
│       ├── PatternDatabase.cpp / .h
│       ├── NibbleArray.cpp / .h
│       ├── math.cpp / .h
│       └── PermutationIndexer.h
├── Solver/
│   ├── DFSSOLVER.h
│   ├── BFSSOLVER.h
│   ├── IDDFSSolver.h
│   └── IDAstarSOLVER.h
├── main.cpp
└── CMakeLists.txt

````

---

## ⚙️ Build Instructions

### ✅ Requirements

- C++17 or above
- g++ / clang++
- (Optional) CLion or any CMake-based IDE

### 🔧 Compile & Run

```bash
g++ -std=c++17 main.cpp -o RubikSolver
./RubikSolver
````

Or, open in CLion and build using CMake.

---

## 💡 Example Usage

### Generate Corner Pattern Database

```cpp
CornerDBMaker dbMaker("Databases/CornerDB.text", 0x99);
dbMaker.bfsAndStore(); // This saves PDB to file
```

### Solve a Cube Using IDA\*

```cpp
RubiksCubeBitboard cube;
cube.randomShuffleColor(5);

IDAstarSolver<RubiksCubeBitboard, HashBitboard> solver(cube, "Databases/CornerDB.text");
auto solution = solver.solve();

for (auto move : solution)
    std::cout << cube.getMove(move) << " ";
```

---

## 📌 Author

**Aneesh Singh Rajoriya**
💼 Full Stack Developer | ⚙️ Systems Builder
📍 Jaipur, India
🔗 [GitHub](https://github.com/asr-orzz)


