#ifndef MODIFIEDASTAR_H
#define MODIFIEDASTAR_H

#include "mainwindow.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include <stack>
#include <cstring>

using namespace std;

constexpr int MAX = 200;
constexpr double INF = numeric_limits<double>::max();

//방위 데이터 상,우상,우,우하,하,좌하,좌,좌상
const int dx[8] = { 0, 1, 1, -1, 0, -1, -1,-1};
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1};

using Pair = pair<int,int>;
using pPair = pair<double, Pair>;

struct Cell {
    int parent_x, parent_y;
    double f,g,h;
    int dir;//진행방향0~7 : 상,우상,우,우하,하,좌하,좌,좌상
};

extern char zmap0[MAX][MAX];
extern char zmap1[MAX][MAX];
extern char zmap2[MAX][MAX];
extern char zmap3[MAX][MAX];
extern char zmap4[MAX][MAX];
extern double costoutput[5];
extern int GRIDX;
extern int GRIDY;

double getTurnCost(int currentDir,int newDir);
bool isEnd(int mapx,int mapy, Pair dst);
bool isInRange(int mapx,int mapy);
double getH(int mapx, int mapy, Pair dst);
int getNewDir(int x, int y, int nx, int ny);
bool aStarWithTurnCost(vector<vector<int>>& map, vector<vector<int>>& weightMap, vector<vector<int>>& teritoryMap, Pair stp, Pair dst, MainWindow* mainwindow);
void aStarReset();
void printMap();

vector<vector<int>> loadFile(const string& filepath);

void tracePathAndCalcFuel(Cell nodCordi[MAX][MAX], Pair dst, MainWindow* mainWindow, vector<vector<int>>& weightMap);

class modifiedastar
{
public:
    modifiedastar();
};

#endif // MODIFIEDASTAR_H
