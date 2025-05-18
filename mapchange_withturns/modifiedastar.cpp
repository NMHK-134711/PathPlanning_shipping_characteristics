#include "modifiedastar.h"

using namespace std;

char zmap0[MAX][MAX];
char zmap1[MAX][MAX];
char zmap2[MAX][MAX];
char zmap3[MAX][MAX];
char zmap4[MAX][MAX];
double costoutput[5]={numeric_limits<double>::max(),
                        numeric_limits<double>::max(),
                        numeric_limits<double>::max(),
                        numeric_limits<double>::max(),
                        numeric_limits<double>::max()};
int GRIDX = 0;
int GRIDY = 0;

double getTurnCost(int currentDir,int newDir){
    int turn_angle = abs(currentDir-newDir);

    if(turn_angle==0){
        return 0.0;//방향전환X
    }else if(turn_angle==1 || turn_angle==7){
        return 5.0;//45도회전
    }else if(turn_angle==2 || turn_angle==6){
        return 32.0;//90도회전
    }else if(turn_angle==3 || turn_angle==5){
        return 37.0;//135도회전
    }else{
        return 42.0;//180도회전
    }
}

bool isDest(int mapx,int mapy, Pair dst){
    return (mapx==dst.first && mapy==dst.second);
}

bool isInRange(int mapx,int mapy){
    return (mapx>=0 && mapx < GRIDX && mapy>=0 && mapy < GRIDX);
}

double getH(int mapx, int mapy, Pair dst){
    return sqrt(pow(mapx-dst.first,2)+ pow(mapy-dst.second,2));
}

int getNewDir(int x, int y, int nx, int ny){
    for (int i=0; i<8;++i){
        if(y+dy[i] == ny && x+dx[i] == nx){//기존노드,신규노드 위치 비교해서 어느방향인지 확인
            return i;
        }
    }
    return -1;//잘못된입력일경우
}

void tracePathAndCalcFuel(Cell nodCordi[MAX][MAX], Pair dst, MainWindow* mainWindow, vector<vector<int>>& weightMap){
    QString zmapText = mainWindow->getZmapText();
    stack<Pair> s;
    int x = dst.first;
    int y = dst.second;
    double totalFuel = 0.0;
    int side = 75;
    int diag = 106;

    char (*currentZmap)[MAX];  // 포인터를 사용하여 현재 zmap을 참조
    if(zmapText == "0") currentZmap = zmap0;
    else if(zmapText == "1") currentZmap = zmap1;
    else if(zmapText == "2") currentZmap = zmap2;
    else if(zmapText == "3") currentZmap = zmap3;
    else if(zmapText == "4") currentZmap = zmap4;
    else return; // 잘못된 zmapText 값일 경우 함수 종료

    s.push({x, y});
    while(!(nodCordi[x][y].parent_x == x && nodCordi[x][y].parent_y == y)){
        int tmpx = nodCordi[x][y].parent_x;
        int tmpy = nodCordi[x][y].parent_y;
        x = tmpx;
        y = tmpy;
        s.push({x, y});
    }

    while(!s.empty()){
        Pair pos = s.top();
        int currX = pos.first;
        int currY = pos.second;
        s.pop();

        if(zmapText == "0") currentZmap[currX][currY] = '*';
        else if(zmapText == "1") currentZmap[currX][currY] = '!';
        else if(zmapText == "2") currentZmap[currX][currY] = '@';
        else if(zmapText == "3") currentZmap[currX][currY] = '#';
        else if(zmapText == "4") currentZmap[currX][currY] = '$';

        double tidalweight = 0.95 + ((weightMap[currX][currY]-1)/59)*(0.1);
        //double debug;

        if(currX > 0 && currentZmap[currX-1][currY] != '.' && currentZmap[currX-1][currY] != ' ' ){
            totalFuel += side * tidalweight;
            //debug=side*tidalweight;
        }
        else if(currY > 0 && currentZmap[currX][currY-1] != '.' && currentZmap[currX][currY-1] != ' '){
            totalFuel += side * tidalweight;
            //debug=side*tidalweight;
        }
        else if(currX > 0 && currY > 0 && currentZmap[currX - 1][currY - 1] != '.' && currentZmap[currX - 1][currY - 1] != ' '){
            totalFuel += diag * tidalweight;
            //debug=diag*tidalweight;
        }
    }

    if(zmapText == "0") costoutput[0] = totalFuel;
    else if(zmapText == "1") costoutput[1] = totalFuel;
    else if(zmapText == "2") costoutput[2] = totalFuel;
    else if(zmapText == "3") costoutput[3] = totalFuel;
    else if(zmapText == "4") costoutput[4] = totalFuel;
}

bool aStarWithTurnCost(
    vector<vector<int>>& map,
    vector<vector<int>>& weightMap,
    vector<vector<int>>& teritoryMap,
    Pair stp, Pair dst,
    MainWindow* mainwindow){
    if(!isInRange(stp.first, stp.second) || !isInRange(dst.first, dst.second))return false;

    bool closedList[MAX][MAX];
    memset(closedList, false, sizeof(closedList));

    Cell nodCordi[MAX][MAX];

    //모든노드 리셋
    for(int i=0;i<GRIDY;++i){
        for(int j=0;j<GRIDX;++j){
            nodCordi[i][j].f = nodCordi[i][j].g = nodCordi[i][j].h = INF;
            nodCordi[i][j].parent_x = nodCordi[i][j].parent_y = -1;
            nodCordi[i][j].dir = -1;
        }
    }

    int sx = stp.first;
    int sy = stp.second;
    nodCordi[sx][sy].f = nodCordi[sx][sy].g = nodCordi[sx][sy].h = 0.0;
    nodCordi[sx][sy].parent_x = sx;
    nodCordi[sx][sy].parent_y = sy;
    nodCordi[sx][sy].dir = 0;

    priority_queue<pPair,vector<pPair>,greater<pPair>> openList;
    openList.push({0.0, {sx,sy}});

    while(!openList.empty()){
        pPair p = openList.top();
        openList.pop();

        int x = p.second.first;
        int y = p.second.second;
        closedList[x][y] = true;

        double nf, ng, nh;

        for(int i = 0; i<8;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(isInRange(nx,ny)){
                //목표점 도달시
                if(isDest(nx, ny, dst)){
                    nodCordi[nx][ny].parent_x = x;
                    nodCordi[nx][ny].parent_y = y;
                    tracePathAndCalcFuel(nodCordi, dst, mainwindow, weightMap);
                    return true;//경로탐색완료 경로는 zmap에저장했어 돌아가
                }

                //아니면 새로운 방향 탐색하는데~
                else if(!closedList[nx][ny] && (map[nx][ny] == 1 || map[nx][ny] == 4)){
                    //벽으로 간주된 위치는 이동 불가하고
                    continue;
                }
                else if(!closedList[nx][ny]){
                    //벽이 아니며 방문목록(closed)에 없으면
                    int newDir = getNewDir(x,y,nx,ny);
                    double turncost = getTurnCost(nodCordi[x][y].dir,newDir);

                    ng = nodCordi[x][y].g + (0.9*weightMap[nx][ny]) + (5*(teritoryMap[nx][ny])-10) + (1.1*turncost);
                    nh = getH(nx,ny,dst);
                    nf = ng + nh;

                    //이번에 탐색한 nf(new f)가 이전에 탐색해서 저장해둔.f보다 작으면 이번걸 저장
                    if(nodCordi[nx][ny].f == INF || nodCordi[nx][ny].f > nf){
                        nodCordi[nx][ny].f = nf;
                        nodCordi[nx][ny].g = ng;
                        nodCordi[nx][ny].h = nh;
                        nodCordi[nx][ny].parent_x = x;
                        nodCordi[nx][ny].parent_y = y;
                        nodCordi[nx][ny].dir = newDir;
                        openList.push({nf, {nx,ny}});
                    }
                }
            }
        }
    }

    return false;//계속해봤는데 경로 안찾아져 뭔가 이상하다고 출력해
}

void aStarReset(){
    for(int i=0;i<GRIDY;++i){
        for(int j=0;j<GRIDX;++j){
            zmap0[i][j] = 0;
            zmap1[i][j] = 0;
            zmap2[i][j] = 0;
            zmap3[i][j] = 0;
            zmap4[i][j] = 0;
        }
    }
}


vector<vector<int>> loadFile(const string& filepath){
    ifstream ifs(filepath);

    if(ifs.is_open()){
        ifs >> GRIDY >> GRIDX;
        vector<vector<int>> result(GRIDY, vector<int>(GRIDX));

        for(int i=0;i<GRIDY;++i){
            for(int j=0;j<GRIDX;++j){
                ifs >> result[i][j];
            }
        }
        return result;
    }
    return vector<vector<int>>();
}

modifiedastar::modifiedastar() {}
