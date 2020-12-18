#include "putBox.h"
#include <cstdlib>

putBox::putBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a){
    this->x0 = x0; this->y0 = y0; this->z0 = z0; this->x1 = x1; this->y1 = y1; this->z1 = z1;
    this->r = r; this->g = g; this->b = b; this->a = a;
}

putBox::~putBox(){

}

// Ativa todos os voxels em um intervalo e os atribui a cor atual do desenho
void putBox::draw(Sculptor &t){
       t.setColor(r,g,b,a);
    for(int i=x0;i<=x1;i++){
        for(int j=y0;j<=y1;j++){
            for(int k=z0;k<=z1;k++){
                t.putVoxel(i,j,k);
            }
        }
    }
}
