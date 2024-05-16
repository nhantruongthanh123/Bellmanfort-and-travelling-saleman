#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

#ifndef BELLMAN_H
#define BELLMAN_H


void BF(int [][20], int, char, int[], int[]);
string BF_Path(int [][20], int, char, char);

void BF2(int [][20], int, char, int[], int[]);
void BF3(int [][20], int, char, int[], int[]);
#endif