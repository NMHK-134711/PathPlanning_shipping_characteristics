#include "mainwindow.h"
#include "modifiedastar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Pair stp,dst;
    vector<vector<int>> grid = loadFile("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\mapchange_withturns\\200FREEMAP.txt");
    vector<vector<int>> weightMap = loadFile("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\200_smo_weights\\20160101_smoothed_weight_map.txt");
    vector<vector<int>> teritory = loadFile("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\mapchange_withturns\\200teritory.txt");

    if(grid.empty() || weightMap.empty()){
        return -1;
    }

    for(int i=0;i<GRIDY;++i){
        for(int j=0;j<GRIDX;++j){
            if(grid[i][j]==2){
                stp = {i,j};
                grid[i][j]=0;
            }
            if(grid[i][j]==3){
                dst = {i,j};
                grid[i][j]=0;
            }
        }
    }

    //숫자맵->문자맵
    for(int i=0;i<GRIDY;++i){
        for(int j=0;j<GRIDX;++j){
            zmap0[i][j] = grid[i][j] + '0';
            zmap1[i][j] = grid[i][j] + '0';
            zmap2[i][j] = grid[i][j] + '0';
            zmap3[i][j] = grid[i][j] + '0';
            zmap4[i][j] = grid[i][j] + '0';
        }
    }

    if(aStarWithTurnCost(grid,weightMap,teritory,stp,dst,&w)){
        //성공시 그냥 넘어가
    }else{
        w.appendConsoleOutput("Fail");
    }

    w.resetGrid();
    w.show();
    return a.exec();
}
