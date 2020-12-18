#include <iostream>
#include <fstream>
#include <vector>
#include "Sculptor.h"
#include "Interpretador.h"
#include "Figurageometrica.h"
using namespace std;

int main(){
 Sculptor *t1;
 Interpretador parser;
 vector <FiguraGeometrica*> figs;
 figs = parser.parse("lugar.txt");

 t1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());
    cout << figs.size() << endl;
 for(size_t i = 0; i < figs.size(); i++){
    figs[i]->draw(*t1);
    }
t1->limpavoxels();
t1->writeOFF("home/dimitri/OFF/lugar_incomp.off");
for(size_t i = 0; i < figs.size(); i++){
    delete figs[i];
}
delete t1;
return 0;
}
