#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "MeasureTime.h"
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createChart(const QString &algName)
{
    string alg = algName.toStdString();
    // Crear series para los datos
    QLineSeries *seriesBest = new QLineSeries();
    QLineSeries *seriesAverage = new QLineSeries();
    QLineSeries *seriesWorst = new QLineSeries();

    seriesBest->setName("Best Case");
    seriesAverage->setName("Average Case");
    seriesWorst->setName("Worst Case");

    int N1 = 200;
    int N2 = 500;
    int N3 = 700;
    int N4 = 1000;
    int N5 = 1500;

    // Generación de datos para los diferentes casos
    vector<int> best_case1(N1);   // Ordenado
    vector<int> worst_case1(N1);  // Orden inverso
    vector<int> avg_case1(N1);    // Valores aleatorios

    vector<int> best_case2(N2);   // Ordenado
    vector<int> worst_case2(N2);  // Orden inverso
    vector<int> avg_case2(N2);    // Valores aleatorios

    vector<int> best_case3(N3);   // Ordenado
    vector<int> worst_case3(N3);  // Orden inverso
    vector<int> avg_case3(N3);    // Valores aleatorios

    vector<int> best_case4(N4);   // Ordenado
    vector<int> worst_case4(N4);  // Orden inverso
    vector<int> avg_case4(N4);    // Valores aleatorios

    vector<int> best_case5(N5);   // Ordenado
    vector<int> worst_case5(N5);  // Orden inverso
    vector<int> avg_case5(N5);    // Valores aleatorios


    // Inicialización de los casos
    iota(best_case1.begin(), best_case1.end(), 1);
    iota(worst_case1.begin(), worst_case1.end(), 1);
    reverse(worst_case1.begin(), worst_case1.end());
    generate(avg_case1.begin(), avg_case1.end(), std::rand);

    // Inicialización de los casos
    iota(best_case2.begin(), best_case2.end(), 1);
    iota(worst_case2.begin(), worst_case2.end(), 1);
    reverse(worst_case2.begin(), worst_case2.end());
    generate(avg_case2.begin(), avg_case2.end(), std::rand);

    // Inicialización de los casos
    iota(best_case3.begin(), best_case3.end(), 1);
    iota(worst_case3.begin(), worst_case3.end(), 1);
    reverse(worst_case3.begin(), worst_case3.end());
    generate(avg_case3.begin(), avg_case3.end(), std::rand);

    // Inicialización de los casos
    iota(best_case4.begin(), best_case4.end(), 1);
    iota(worst_case4.begin(), worst_case4.end(), 1);
    reverse(worst_case4.begin(), worst_case4.end());
    generate(avg_case4.begin(), avg_case4.end(), std::rand);

    // Inicialización de los casos
    iota(best_case5.begin(), best_case5.end(), 1);
    iota(worst_case5.begin(), worst_case5.end(), 1);
    reverse(worst_case5.begin(), worst_case5.end());
    generate(avg_case5.begin(), avg_case5.end(), std::rand);

    MeasureTime medida;

    auto wc1 = medida.measureTime(alg, worst_case1);
    auto wc2 = medida.measureTime(alg, worst_case2);
    auto wc3 = medida.measureTime(alg, worst_case3);
    auto wc4 = medida.measureTime(alg, worst_case4);
    auto wc5 = medida.measureTime(alg, worst_case5);

    seriesWorst->append(N1, wc1);
    seriesWorst->append(N2, wc2);
    seriesWorst->append(N3, wc3);
    seriesWorst->append(N4, wc4);
    seriesWorst->append(N5, wc5);


    auto avg1 = medida.measureTime(alg, avg_case1);
    auto avg2 = medida.measureTime(alg, avg_case2);
    auto avg3 = medida.measureTime(alg, avg_case3);
    auto avg4 = medida.measureTime(alg, avg_case4);
    auto avg5 = medida.measureTime(alg, avg_case5);

    seriesAverage->append(N1, avg1);
    seriesAverage->append(N2, avg2);
    seriesAverage->append(N3, avg3);
    seriesAverage->append(N4, avg4);
    seriesAverage->append(N5, avg5);


    auto bc1 = medida.measureTime(alg, best_case1);
    auto bc2 = medida.measureTime(alg, best_case2);
    auto bc3 = medida.measureTime(alg, best_case3);
    auto bc4 = medida.measureTime(alg, best_case4);
    auto bc5 = medida.measureTime(alg, best_case5);

    // Agregar datos a las series, pares ordenados
    seriesBest->append(N1, bc1);
    seriesBest->append(N2, bc2);
    seriesBest->append(N3, bc3);
    seriesBest->append(N4, bc4);
    seriesBest->append(N5, bc5);


    // Crear el gráfico y usar el nombre del algoritmo en el título
    QChart *chart = new QChart();
    chart->addSeries(seriesBest);
    chart->addSeries(seriesAverage);
    chart->addSeries(seriesWorst);

    // Configurar el título del gráfico utilizando algName
    chart->setTitle("Rendimiento de " + algName);
    chart->createDefaultAxes();
    chart->legend()->show();

    // Habilitar la leyenda para mostrar el nombre de las series
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configurar los ejes
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Tamano N");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    seriesBest->attachAxis(axisX);
    seriesAverage->attachAxis(axisX);
    seriesWorst->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Tiempo ms");
    axisY->setLabelFormat("%d");
    axisY->setTickCount(5);
    chart->addAxis(axisY, Qt::AlignLeft);
    seriesBest->attachAxis(axisY);
    seriesAverage->attachAxis(axisY);
    seriesWorst->attachAxis(axisY);

    // Crear el QChartView y añadirlo al layout de la ventana
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Suponiendo que tienes un layout en tu UI llamado "verticalLayout"
    ui->verticalLayout->addWidget(chartView);
}

void MainWindow::on_pushButton_clicked()
{

    QString alg = ui->algoritmo->text();


    createChart(alg);

}



