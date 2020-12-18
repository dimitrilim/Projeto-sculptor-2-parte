#include "Sculptor.h" // Header onde está declarada a classe Sculptor
#include <iostream>   // Header de entrada e saida de dados
#include <cstdlib>    // Header usado para o exit
#include <fstream>
#include <string>
#include <queue>

using namespace std;

// Construtor da classe
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    if (_nx <= 0 || _ny <= 0 || _nz <= 0){
        _nx = _ny = _nz = 0;
    }
// Alocaçao da matriz 3d
    v = new Voxel **[_nz];
    if ( v == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0] = new Voxel*[_nz*_ny];
    if (v[0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0][0] = new Voxel[_nx*_ny*_nz];
    if (v[0][0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }

    for (int i = 1; i < _nz; i++){
        v[i] = v[i-1] + _nz;
    }

    for (int j = 1; j < (_nz*_ny); j++){
        v[0][j] = v[0][j-1] + _nx;

    }
}
// Destrutor da classe
Sculptor::~Sculptor(){

// Liberando a memoria alocada
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

// Define a cor atual do desenho
void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    if(r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1 || alpha < 0 || alpha > 1){
        cout << "Dimensao errada na funcao setColor" << endl;
        exit(1);
    }
      r = _r;
      g = _g;
      b = _b;
      a = alpha;

}

// Ativa o voxel em uma posição (x,y,z) e faz isOn = true
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    }


// Desativa o voxel em uma posição (x,y,z) e faz isOn = false
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::limpavoxels(void){
  std::queue<int> q;
  int x, y, z;
  int lx,ly,lz;
  for(x=1; x<nx-1; x++){
    for(y=1; y<ny-1; y++){
      for(z=1; z<nz-1; z++){
        if((v[x][y][z].isOn == true) &&
           (v[x+1][y][z].isOn == true) &&
           (v[x-1][y][z].isOn == true) &&
           (v[x][y+1][z].isOn == true) &&
           (v[x][y-1][z].isOn == true) &&
           (v[x][y][z+1].isOn == true) &&
           (v[x][y][z-1].isOn == true)){
          q.push(x);
          q.push(y);
          q.push(z);
        }
      }
    }
  }
  while(!q.empty()){
    lx=q.front(); q.pop();
    ly=q.front(); q.pop();
    lz=q.front(); q.pop();
    v[lx][ly][lz].isOn = false;
  }
}

// Função que grava o arquivo OFF
void Sculptor::writeOFF(char *filename){

    // Variaveis para o número de vertices, faces e arestas
    int nv = 0;
    int nf = 0;

    // Variaveis aux para face de cada voxel
    int Faux = 0;

    // Classe de fluxo que permite operação em arquivos
    ofstream aux2;

    // Abertura/ criação de arquivo OFF
    aux2.open(filename);

    // Verificação se o arquivo OFF foi aberto
    if( aux2.is_open()){
        cout << "Arquivo OFF aberto com sucesso\n" << endl;
    }
    else{
        cout << "Abertura de arquivo OFF falhou\n" << endl;
        exit(1);
    }
    // Primeira linha do arquivo. Palavra obrigatóŕia em arquivos OFF
    aux2 << "OFF" << endl;

    // Contagem de vertices e faces, que serao incluidos na escultura
    for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn ){
                    nv = nv + 8;
                    nf = nf + 6;
                } // if
            } // for k
        } // for j
    } // for i

    // 2 linha do arquivo OFF, mostrando a quantidade de vertices, faces e arestas
    aux2<< nv << " " << nf << " " << 0 << endl;

    // Criando as dimensoes dos vertices da figura, para cada voxel ativo, o voxel tem dimensão igual a 1
     for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    aux2 << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    aux2 << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    aux2 << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    aux2 << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    aux2 << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    aux2 << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    aux2 << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    aux2 << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                } // if
            } // for k
        } // for j
     } // for i

    // Criando as dimensões das faces e atribuindo as cores, para cada voxel ativo
     for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                        aux2 << 4 <<" "<< Faux + 0 <<" "<< Faux + 3 <<" "<< Faux + 2 <<" "<< Faux + 1 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux2<< 4 <<" "<< Faux + 4 <<" "<< Faux + 5 <<" "<< Faux + 6 <<" "<< Faux + 7 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux2<< 4 <<" "<< Faux + 0 <<" "<< Faux + 1 <<" "<< Faux + 5 <<" "<< Faux + 4 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux2<< 4 <<" "<< Faux + 0 <<" "<< Faux + 4 <<" "<< Faux + 7 <<" "<< Faux + 3 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux2<< 4 <<" "<< Faux + 3 <<" "<< Faux + 7 <<" "<< Faux + 6 <<" "<< Faux + 2 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux2<< 4 <<" "<< Faux + 1 <<" "<< Faux + 2 <<" "<< Faux + 6 <<" "<< Faux + 5 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        Faux = Faux + 8;
                } // if
            } // for k
        } // for j
     } // for i



    // Salvando arquivo
    if(aux2.is_open()){
        cout << "Arquivo OFF salvo com sucesso" << endl;
    }

    // Fechando o arquivo
    aux2.close();

}


