#ifndef PUTBOX_H
#define PUTBOX_H

#include "Figurageometrica.h"
#include "Sculptor.h"


/** \brief Classe responsavel por colocar uma sequencia de voxels em forma de caixa e deixando ativo (isOn = true)
 * \param x0 (Dimensão inicial em x)
 * \param y0 (Dimensão inicial em y)
 * \param z0 (Dimensão inicial em z)
 * \param x1 (Dimensão final em x)
 * \param y1 (Dimensão final em y)
 * \param z1 (Dimensão final em z)
 * \return
 *
 */

class putBox: public FiguraGeometrica{
    int x0, y0, z0, x1, y1, z1;
    public:

        /** \brief Define a região retangular a ser inserida na escultura e atribui a cor e transparncia especificada
        *
        * \param x0, y0, z0, x1, y1, z1, r, g ,b, a
        *
        */

        putBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a);

        /** \brief Destrutor da classe
        */

        virtual ~putBox();

        /** \brief É o método que desenha a escultura
        * \param t (Onde a escultura será alocada)
        * \return void
        */

        void draw(Sculptor &t);
};

#endif // PUTBOX_H
