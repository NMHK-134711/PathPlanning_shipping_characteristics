#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getDateText() const;
    QString getMonthText() const;
    QString getYearText() const;
    QString getZmapText() const;
    QString costoutputstring(double cost);

    void findlowestfuelcost();
    void appendConsoleOutput(const QString& text);
    void displayGrid();
    void resetGrid();
    int lowest=0;//경로중 코스트가 가장 낮은 경로의인덱스

    //bool randomtoggled();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_reset_clicked();
    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
