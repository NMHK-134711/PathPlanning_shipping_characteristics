#include "ui_mainwindow.h"
#include "modifiedastar.h"

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QColor>
#include <QPixmap>

#include <random>
#include <chrono>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    displayGrid();

    QGraphicsScene *scene2 = new QGraphicsScene(this);
    QPixmap pixmap("C:\\Users\\82102\\Desktop\\baram project\\logo.png");
    QGraphicsPixmapItem *imageItem = new QGraphicsPixmapItem(pixmap);
    scene2->addItem(imageItem);
    ui->logo->setScene(scene2);
    ui->logo->fitInView(imageItem,Qt::KeepAspectRatio);

    aStarReset();
    resetGrid();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);
    ui->logo->fitInView(ui->logo->scene()->itemsBoundingRect(),Qt::KeepAspectRatio);
}

void MainWindow::resetGrid(){
    QString zmapText = MainWindow::getZmapText();
    if (zmapText == "0"){
        memset(zmap0, 0, sizeof(zmap0));
    } else if(zmapText == "1"){
        memset(zmap1, 0, sizeof(zmap1));
    } else if(zmapText == "2"){
        memset(zmap2, 0, sizeof(zmap2));
    } else if(zmapText == "3"){
        memset(zmap3, 0, sizeof(zmap3));
    } else if(zmapText == "4"){
        memset(zmap4, 0, sizeof(zmap4));
    }
    displayGrid();
}

void MainWindow::displayGrid(){
    scene->clear();

    int cellSize = 5;

    QPixmap background("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\map_image.png");
    background = background.scaled(GRIDX*cellSize,GRIDY*cellSize);
    QGraphicsPixmapItem *bgItem = scene->addPixmap(background);
    bgItem->setZValue(-1);

    for(int i=0;i<GRIDY;++i){
        for(int j=0;j<GRIDX;++j){
            QBrush brush;
            if(zmap0[i][j]=='0'||zmap0[i][j]=='4'){
                QColor white70 = Qt::white;
                white70.setAlphaF(0.00001);
                brush.setColor(white70);
            }
            else if(zmap0[i][j]=='1'){
                QColor black70 = Qt::black;
                black70.setAlphaF(1);
                brush.setColor(black70);
            }
            else if(zmap0[i][j]=='*'){
                QColor red70 = Qt::red;
                red70.setAlphaF(0.7);
                brush.setColor(red70);
            }
            else if(zmap1[i][j]=='!'){
                QColor green70 = Qt::green;
                green70.setAlphaF(0.7);
                brush.setColor(green70);
            }
            else if(zmap2[i][j]=='@'){
                QColor y70 = Qt::yellow;
                y70.setAlphaF(0.7);
                brush.setColor(y70);
            }
            else if(zmap3[i][j]=='#'){
                QColor b70 = Qt::blue;
                b70.setAlphaF(0.7);
                brush.setColor(b70);
            }
            else if(zmap4[i][j]=='$'){
                QColor m70 = Qt::magenta;
                m70.setAlphaF(0.7);
                brush.setColor(m70);
            }
            else{continue;}


            brush.setStyle(Qt::SolidPattern);
            scene->addRect(j*cellSize,i*cellSize,cellSize,cellSize,QPen(),brush);
        }
    }
}

void MainWindow::appendConsoleOutput(const QString &text){
    ui->outputconsole->append(text);
}

void MainWindow::on_reset_clicked(){
    aStarReset();
    resetGrid();
    appendConsoleOutput("Reset.");
}

void MainWindow::findlowestfuelcost(){
    double low = std::numeric_limits<double>::max();
    lowest = -1;
    for (int i = 0; i < 5; ++i) {
        if (costoutput[i] < low) {
            low = costoutput[i];
            lowest = i;
        }
    }
}

/*bool MainWindow::randomtoggled(){
    if(ui->random->isChecked()){
        return true;
    }
    else{false;}
}*/

void MainWindow::on_start_clicked(){
    QString zmapText = MainWindow::getZmapText();
    if (zmapText == "0"){
        memset(zmap0, 0, sizeof(zmap0));
    } else if(zmapText == "1"){
        memset(zmap1, 0, sizeof(zmap1));
    } else if(zmapText == "2"){
        memset(zmap2, 0, sizeof(zmap2));
    } else if(zmapText == "3"){
        memset(zmap3, 0, sizeof(zmap3));
    } else if(zmapText == "4"){
        memset(zmap4, 0, sizeof(zmap4));
    }


    /*if(randomtoggled()==true){
        random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution<> distr()
    }*/
    QString selectedDate = (getYearText() + getMonthText() + getDateText());
    QString filePath = "C:\\Users\\82102\\Desktop\\baram project\\2024-2\\200_smo_weights\\" + selectedDate + "_smoothed_weight_map.txt";
    vector<vector<int>> weightMap = loadFile(filePath.toStdString());
    if(weightMap.empty()){
        appendConsoleOutput("Failed to load weight map.");
        appendConsoleOutput("Check DateValue");
        return;
    }

    Pair stp, dst;
    vector<vector<int>> grid = loadFile("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\mapchange_withturns\\200FREEMAP.txt");
    vector<vector<int>> teritory = loadFile("C:\\Users\\82102\\Desktop\\baram project\\2024-2\\mapchange_withturns\\200teritory.txt");

    for(int i = 0; i < GRIDY; ++i){
        for(int j = 0; j < GRIDX; ++j){
            if(grid[i][j] == 2){
                stp = {i, j}; // 시작점
                grid[i][j] = 0; // 시작점 위치를 0으로 변경
            }
            if(grid[i][j] == 3){
                dst = {i, j}; // 도착점
                grid[i][j] = 0; // 도착점 위치를 0으로 변경
            }
        }
    }

    auto start=std::chrono::high_resolution_clock::now();

    if(aStarWithTurnCost(grid,weightMap,teritory,stp,dst,this)){
        displayGrid();
    } else{
        appendConsoleOutput("Fail");
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

    ui->outputconsole->clear();
    appendConsoleOutput("Path Genarated");
    appendConsoleOutput("Calculation time is "+QString::number(dura.count())+"ms");

    QGraphicsScene *scene3 = new QGraphicsScene(this);
    QString visualPath = "C:\\Users\\82102\\Desktop\\baram project\\2024-2\\output_images\\" + selectedDate + "_weight_map.png";
    QPixmap visualize(visualPath);
    QGraphicsPixmapItem *visualItem = new QGraphicsPixmapItem(visualize);
    scene3->addItem(visualItem);
    ui->graphicsView_2->setScene(scene3);
    ui->graphicsView_2->fitInView(visualItem,Qt::KeepAspectRatio);

    if(zmapText == "0"){
        ui->corse0->clear();
        ui->corse0->append(selectedDate+"'s FuelCost is");
        ui->corse0->append(costoutputstring(costoutput[0]));
    }else if(zmapText == "1"){
        ui->corse1->clear();
        ui->corse1->append(selectedDate+"'s FuelCost is");
        ui->corse1->append(costoutputstring(costoutput[1]));
    }else if(zmapText == "2"){
        ui->corse2->clear();
        ui->corse2->append(selectedDate+"'s FuelCost is");
        ui->corse2->append(costoutputstring(costoutput[2]));
    }else if(zmapText == "3"){
        ui->corse3->clear();
        ui->corse3->append(selectedDate+"'s FuelCost is");
        ui->corse3->append(costoutputstring(costoutput[3]));
    }else if(zmapText == "4"){
        ui->corse4->clear();
        ui->corse4->append(selectedDate+"'s FuelCost is");
        ui->corse4->append(costoutputstring(costoutput[4]));
    }

    findlowestfuelcost();
    appendConsoleOutput("");
    appendConsoleOutput("Recomended Path is Path"+QString::number(lowest));
    appendConsoleOutput("Current WeightImage is "+selectedDate);
}

QString MainWindow::costoutputstring(double cost){
    int a = static_cast<int>(cost/10000);
    double b = cost - a*10000;
    QString num = (QString::number(a)+"억"+QString::number(b)+"만원");
    return num;
}

QString MainWindow::getYearText() const{
    return ui->year->currentText();
}

QString MainWindow::getMonthText() const{
    return ui->month->currentText();
}

QString MainWindow::getDateText() const{
    return ui->date->currentText();
}

QString MainWindow::getZmapText() const{
    return ui->zmap->currentText();
}
