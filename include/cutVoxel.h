#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "Figurageometrica.h"
#include "Sculptor.h"

/** \brief Classe responsavel por cortar um voxel na posição (x,y,z) e deixando inativo (isOn = false)
 *
 * \param x (Posição em x)
 * \param y (Posição em y)
 * \param z (Posição em z)
 */

class cutVoxel: public FiguraGeometrica{
    int x, y, z;
public:
    /** \brief Define o voxel a ser excluido
     *
     * \param x , y ,z
     *
     */

    cutVoxel(int x, int y, int z);

    /** \brief Destrutor da classe
     */

    virtual ~cutVoxel();

    /** \brief É o método que desenha a escultura
     * \param t (Onde a escultura será alocada)
     * \return void
     */

    void draw(Sculptor &t);

};

#endif // CUTVOXEL_H
