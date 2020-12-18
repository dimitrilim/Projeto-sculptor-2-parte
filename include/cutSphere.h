#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsável por desativar todos os voxels que satisfazem a equação da esfera (isOn = false)
 *
 * \param xcenter ( Posição x do centro da esfera)
 * \param ycenter ( Posição y do centro da esfera)
 * \param zcenter ( Posição z do centro da esfera)
 * \param radius ( Raio da esfera)
 *
 */

class cutSphere: public FiguraGeometrica{
    int xcenter,ycenter, zcenter, radius;
public:

    /** \brief Determina as dimensões da esfera que será apagada
     *
     * \param xcenter, ycenter, zcenter, radius
     */

    cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /** \brief Destrutor da classe
     */

    virtual ~cutSphere();

    /** \brief É o método que desenha a escultura
     * \param t (Onde a escultura será alocada)
     * \return void
     */

    void draw(Sculptor &t);

};

#endif // CUTSPHERE_H
