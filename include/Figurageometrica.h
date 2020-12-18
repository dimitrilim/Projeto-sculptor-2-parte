#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Sculptor.h"
/** \brief A classe Figura Geometrica é uma classe abstrata em que faz a conexao entre as demais classes por meio de herança
 *
 * \param r(vermelho), g(verde) ,b(azul), a(transparencia)
 *
 */

class FiguraGeometrica{
protected:
    float r,g,b,a;
public:
    /** \brief Construtor da classe
     *
     */

    FiguraGeometrica();
    /** \brief Destrutor virtual da classe
     *
     */

    virtual ~FiguraGeometrica();

    /** \brief É a funçao responsavel por desenhar a figura 3d
     * \param t
     * \remarks é uma função virtual pura
     * \return void
     *
     */

    virtual void draw(Sculptor &t) = 0;

};

#endif // FIGURAGEOMETRICA_H
