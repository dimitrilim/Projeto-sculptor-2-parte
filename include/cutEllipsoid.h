#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsável por desativar todos os voxels que satisfazem a equação da elipsoide
         *
         * \param xcenter ( Posição x do centro da elipse)
         * \param ycenter ( Posição y do centro da elipse)
         * \param zcenter ( Posição z do centro da elipse)
         * \param rx ( Raio da elipse na dimensão x)
         * \param ry ( Raio da elipse na dimensão y)
         * \param rz ( Raio da elipse na dimensão z)
         *
         */

class cutEllipsoid:public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    public:

        /** \brief Define a região em forma de elipse a ser removida
         *
         * \param xcenter, ycenter, zcenter, rx, ry, rz
         */


        cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

        /** \brief Destrutor da classe
         */

        virtual ~cutEllipsoid();

        /** \brief É o método que desenha a escultura
        * \param t (Onde a escultura será alocada)
        * \return void
        */

        void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
