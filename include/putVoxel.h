#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "Figurageometrica.h"
#include "Sculptor.h"


/** \brief Classe responsavel por um voxel em uma posição (x,y,z) e deixando ativo (isOn = true)
 *
 * \param x ( Posição na dimensão x)
 * \param y ( Posição na dimensão y)
 * \param z ( Posição na dimensão z)
 *
 */


class putVoxel: public FiguraGeometrica{
    int x, y, z;
public:

    /** \brief Define o local para inserir o voxel atribuindo a cor e transparencia especificadas
     *
     * \param x, y, z, r, g ,b, a
     */

    putVoxel(int x, int y, int z, float r, float g, float b, float a);

    /** \brief Destrutor da classe
     */

    virtual ~putVoxel();

    /** \brief É o método que desenha a escultura
     * \param t (Onde a escultura será alocada)
     * \return void
     */

    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
