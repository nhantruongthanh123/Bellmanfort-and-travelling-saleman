#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

#ifndef BELLMAN_H
#define BELLMAN_H


void BF(int [][1000], int, char, int[], int[]);
string BF_path(int [][1000], int, char, char);

#endif