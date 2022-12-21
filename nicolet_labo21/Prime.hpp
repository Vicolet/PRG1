/**
 * Nom du fichier  : Prime.hpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-12
 * Laboratoire n°  : 21
 * Description     :
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "Uint.hpp"
#include <iostream>
#include <functional>
#include <random>

/**
 *
 * @param base
 * @param exposant
 * @param modulo
 * @return
 */
Uint exponentiationModulaire(Uint base, Uint exposant, Uint modulo);

/**
 *
 * @param nombrePremier ce paramètre représente la valeur sur la quelle on veut faire le test de primalité.
 * @return un booléen pour savoir si le nombre tester est premier True si premier False si pas premier.
 */
bool prime(Uint nombrePremier);
