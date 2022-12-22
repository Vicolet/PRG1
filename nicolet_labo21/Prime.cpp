//
// Created by victo on 20.12.2022.
//

#include "Prime.hpp"

Uint exponentiationModulaire(Uint base, Uint exposant, Uint modulo) {
    Uint r(1);

    while (exposant > 0) {
        if (exposant % 2 == 0) {
            base = (base * base) % modulo;
            exposant = exposant / 2;
        } else {
            r = (r * base) % modulo;
            exposant--;
        }
    }
    return r;
}

bool prime(Uint nombrePremier) {
    if (nombrePremier < 2) {
        return false;
    }
    if (nombrePremier == 2) {
        return true;
    }
    auto gen_int1_3 = std::bind(std::uniform_int_distribution<uint64_t>(1, uint64_t(nombrePremier - 1)),
                                std::mt19937(987));

    for (uint64_t i = 0; i != 10; i++) {
        Uint alea(gen_int1_3());

        if (exponentiationModulaire(alea, nombrePremier - 1, nombrePremier) != (1 % nombrePremier))
            return false;

        Uint q = 1, u = nombrePremier - 1;

        while ((u % 2 == 0) && (q == 1)) {
            u = u / 2;
            q = exponentiationModulaire(alea, u, nombrePremier);

            if ((q != 1) && (q != nombrePremier - 1)) {
                return false;
            }
        }
    }
    return true;
}