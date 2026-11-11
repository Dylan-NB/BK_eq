## 1. Setup (first time only, or if you add/rename/remove source files)
conda activate bk_eq

cmake -S . -B build

## 2. Compile and run (every time you edit existing code)
cmake --build build

./build/main
