#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsável por ativar todos os voxels que satisfaz a equação da elipsoide
 *
 * \param xcenter ( Posição x do centro da elipse)
 * \param ycenter ( Posição y do centro da elipse)
 * \param zcenter ( Posição z do centro da elipse)
 * \param rx ( Raio da elipse na dimensão x)
 * \param ry ( Raio da elipse na dimensão y)
 * \param rz ( Raio da elipse na dimensão z)
 *
 */

class putEllipsoid: public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
    public:

        /** \brief Define a região que será inserida a elipse e atribui a cor e transparencia especificada
         *
         * \param xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a
         */

        putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);

        /** \brief Destrutor da classe
        */

        virtual ~putEllipsoid();

        /** \brief É o método que desenha a escultura
        * \param t (Onde a escultura será alocada)
        * \return void
        */

        void draw(Sculptor &t);

};

#endif // PUTELLIPSOID_H
