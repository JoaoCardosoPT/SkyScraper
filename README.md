## 4x4 SkyScrappers

## Puzzle Rules
Fill the grid with building heights from 1 to 4 so that:

- Each height appears exactly once in every row and column.
- Taller buildings hide shorter buildings behind them.

## Build

Requires a C compiler such as GCC or Clang and a Unix-compatible environment.

cc main.c input.c grid.c algo.c -o rush-01

## Usage

Pass all 16 clues as a single quoted argument:

./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

The program prints Error if the input format is invalid or the search finds
no solution.
