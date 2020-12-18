#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Figurageometrica.h"
#include <string>
#include <vector>

using namespace std;
/** \brief A classe interpretador é a responsável por decodificar o desenho que será gerado
 * \param dimx(dimensão em x)
 * \param dimy(dimensão em y)
 * \param dimz(dimensão em z)
 * \param r(vermelho)
 * \param g(verde)
 * \param b(azul)
 * \param a(transparencia)
 *
 */

class Interpretador{
    int dimx, dimy, dimz;
    float r,g,b,a;
public:
    /** \brief Construtor padrao da classe
     */

    Interpretador();
    vector <FiguraGeometrica *> parse(string filename);

    /** \brief getDimx
     * \return Dimensão em x da matriz
     *
     */

    int getDimx();

    /** \brief getDimy
     * \return Dimensão em y da matriz
     */


    int getDimy();

    /** \brief getDimz
     * \return Dimensão em z da matriz
     */

    int getDimz();
};

#endif // INTERPRETADOR_H
