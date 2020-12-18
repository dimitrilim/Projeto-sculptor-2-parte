#include "Interpretador.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"


using namespace std;

Interpretador::Interpretador(){

}

vector< FiguraGeometrica *> Interpretador::parse(string filename){
    vector <FiguraGeometrica *> figs;
    ifstream aux;
    stringstream ss;
    string s, token;

    aux.open("teste.txt");
    if(!aux.is_open()){
       cout << "Abertura de arquivo txt falhou\n" << endl;
       exit(1);
    }

    while(aux.good()){
        getline(aux,s);
        if(aux.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if(token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
            }
                else if (token.compare("putvoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new putVoxel(x, y, z, r, g, b, a));
                }
                else if (token.compare("cutvoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figs.push_back(new cutVoxel(x, y, z));
                }
                else if (token.compare("putbox") == 0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new putBox(x0, y0, z0, x1, y1, z1, r, g, b, a));
                }
                else if (token.compare("cutbox") == 0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
                    figs.push_back(new cutBox(x0, y0, z0, x1, y1, z1));
                }
                else if (token.compare("putsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                }
                else if (token.compare("cutsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if (token.compare("putellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
                }
                else if (token.compare("cutellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz ;
                    figs.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
return (figs);
}

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}


