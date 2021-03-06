#include "display.h"
#include "ui_display.h"
#include <string.h>
#include <QString>
#include <QTimer>
#include <iostream>

using namespace std;


Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    reg= new registro();

    // Initialize the library using United States style license plates.
    // You can use other countries/regions as well (for example: "eu", "au", or "kr")
    //alpr::Alpr openalpr("us", "/home/diego/openalpr/config/openalpr.conf.defaults");
    openalpr=new alpr::Alpr("eu", "/home/gabrielrudloff/openalpr/config/openalpr.conf.defaults");

    // Optionally specify the top N possible plates to return (with confidences).  Default is 10
    openalpr->setTopN(10);

    // Optionally, provide the library with a region for pattern matching.  This improves accuracy by
    // comparing the plate text with the regional pattern.
    //openalpr.setDefaultRegion("md");

    // Make sure the library loaded before continuing.
    // For example, it could fail if the config/runtime_data is not found
    if (openalpr->isLoaded() == false)
    {
        std::cerr << "Error loading OpenALPR" << std::endl;
        //return 1;
    }

    // Recognize an image file.  You could alternatively provide the image bytes in-memory.
    //results = openalpr->recognize("/home/gabrielrudloff/temp/foto.jpg");

    // Iterate through the results.  There may be multiple plates in an image,
    // and each plate return sthe top N candidates.
//    if(results.plates.size()==0)
//        std::cout<<"Cero Patentes!"<< std::endl;
//    for (int i = 0; i < int(results.plates.size()); i++)
//    {
//      alpr::AlprPlateResult plate = results.plates[i];
//      std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

//        for (int k = 0; k < plate.topNPlates.size(); k++)
//        {
//          alpr::AlprPlate candidate = plate.topNPlates[k];
//          std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
//          std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
//        }
//    }

    string str="Patente: Desconocido \n Nombre: Desconocido\n Cargo: Desconocido";
    QString qstr=QString::fromStdString(str);
    ui->info->setText(qstr);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

}




Display::~Display()
{
    delete ui;
}

void Display::on_reg_bot_clicked()
{
    registro_win registro_window(this, reg);
    registro_window.setModal(true);
    registro_window.exec();
}

void Display::on_buscar_bot_clicked()
{
    Buscar_win buscar_window(this, reg);
    buscar_window.setModal(true);
    buscar_window.exec();
}

void Display::update()
{
    results = openalpr->recognize("/home/gabrielrudloff/temp/foto.jpg");
        if(results.plates.size()!=0){
            QString patente=QString::fromStdString(results.plates[0].topNPlates[0].characters);
            if(patente!=last_patente){
                QString qstr = "Patente: "+ patente+"\n"+"Nombre: Desconocido \n Cargo: Desconocido" ;
                ui->info->setText(qstr);
                car* cars = reg->check(patente);
                if(cars!=nullptr){
                    QString qstr = "Patente: "+ cars->getPatente()+"\n"+"Nombre: "+ cars->getNombre()+"\n" + "Cargo: "+ cars->getCargo();
                    ui->info->setText(qstr);
                }
                last_patente=patente;
            }
        }

//        if(!reg->isEmpty()){
//            car* cars= reg->getLast();
//            QString qstr = "Patente: "+ cars->getPatente()+"\n"+"Nombre: "+ cars->getNombre()+"\n" + "Cargo: "+ cars->getCargo();
//            ui->info->setText(qstr);
//        }
}

