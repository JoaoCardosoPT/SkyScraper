#ifndef RUSH01_H
#define RUSH01_H

void start_grid(int grid[4][4], int clu[4][4]);

void save_clues(char *str, int clues[4][4]);
int  valid_input(char *str);
void printgrid(int grid[4][4]);
void clear_grid(int grid[4][4]);

#endif
