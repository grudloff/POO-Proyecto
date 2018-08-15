#include "display.h"
#include "ui_display.h"
#include "registro_win.h"
#include "buscar_win.h"
#include "alpr.h"
#include <string.h>
#include <QString>
using namespace std;

Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    // Initialize the library using United States style license plates.
    // You can use other countries/regions as well (for example: "eu", "au", or "kr")
    alpr::Alpr openalpr("us", "/home/gabrielrudloff/openalpr/config/openalpr.conf.defaults");

    // Optionally specify the top N possible plates to return (with confidences).  Default is 10
    openalpr.setTopN(10);

    // Optionally, provide the library with a region for pattern matching.  This improves accuracy by
    // comparing the plate text with the regional pattern.
    //openalpr.setDefaultRegion("md");

    // Make sure the library loaded before continuing.
    // For example, it could fail if the config/runtime_data is not found
    if (openalpr.isLoaded() == false)
    {
        std::cerr << "Error loading OpenALPR" << std::endl;
        //return 1;
    }

    // Recognize an image file.  You could alternatively provide the image bytes in-memory.
    alpr::AlprResults results = openalpr.recognize("/home/gabrielrudloff/Desktop/ea7the.jpg");

    // Iterate through the results.  There may be multiple plates in an image,
    // and each plate return sthe top N candidates.
    if(results.plates.size()==0)
        std::cout<<"Cero Patentes!"<< std::endl;
    for (int i = 0; i < int(results.plates.size()); i++)
    {
      alpr::AlprPlateResult plate = results.plates[i];
      std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

        for (int k = 0; k < plate.topNPlates.size(); k++)
        {
          alpr::AlprPlate candidate = plate.topNPlates[k];
          std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
          std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
        }
    }

    string str="Patente: "+results.plates[0].topNPlates[0].characters+"\n"+"Nombre: Desconocido\n" + "Cargo: Desconocido";
    QString qstr=QString::fromStdString(str);
    ui->info->setText(qstr);

}

Display::~Display()
{
    delete ui;
}

void Display::on_reg_bot_clicked()
{
    registro_win registro_window;
    registro_window.setModal(true);
    registro_window.exec();
}

void Display::on_buscar_bot_clicked()
{
    Buscar_win buscar_window;
    buscar_window.setModal(true);
    buscar_window.exec();
}