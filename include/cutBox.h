#ifndef CUTBOX_H
#define CUTBOX_H

#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsavel por cortar uma sequencia de voxels em forma de cubo e deixando inativo (isOn = false)
 *
 * \param x0 (Dimensão inicial do corte em x)
 * \param x1 (Dimensão final do corte em x)
 * \param y0 (Dimensão inicial do corte em y)
 * \param y1 (Dimensão final do corte em y)
 * \param z0 (Dimensão inicial do corte em z)
 * \param z1 (Dimensão final do corte em z)
 *
 */

class cutBox:public FiguraGeometrica{
    int x0, y0, z0, x1, y1, z1;
public:
    /** \brief Função que determina as dimensões em formato retangular para ser removida da escultura
     *
     * \param x0, y0, z0, x1, y1, z1
     */

    cutBox(int x0, int y0, int z0, int x1, int y1, int z1);

    /** \brief Destrutor da classe
     *
     */

     virtual ~cutBox();

    /** \brief É o método que desenha a escultura
     * \param t (Onde a escultura será alocada)
     * \return void
     */


    void draw(Sculptor &t);
};

#endif // CUTBOX_H
