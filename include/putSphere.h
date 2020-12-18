#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsável por ativar todos os voxels que satisfazem a equação da esfera
 *
 * \param xcenter ( Posição x do centro da esfera)
 * \param ycenter ( Posição y do centro da esfera)
 * \param zcenter ( Posição z do centro da esfera)
 * \param radius ( Raio da esfera)
 * \return
 *
 */


class putSphere: public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:

    /** \brief Define a região esferica a ser incluida na escultura e atribui a cor e trasnparencia especificada
     *
     * \param xcenter, ycenter, zcenter, radius, r, g, b ,a
     */


    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);

    /** \brief Destrutor da classe
     */

    virtual ~putSphere();

     /** \brief É o método que desenha a escultura
     * \param t (Onde a escultura será alocada)
     * \return void
     */

    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
