//
// Created by emilf on 07.07.2025.
//
#include "Port.h"
#include <iostream>
#include <ctime>

int main()
{
    srand(static_cast<unsigned>(time(0))); // Initialisiert Zufallsgenerator

    Port port;

    // Beispielhafte Schiffe hinzufügen
    port.addShip(Ship("Poseidon", "Container", rand() % 25 + 1, rand() % 6 + 1));
    port.addShip(Ship("Neptune", "Gas", rand() % 25 + 1,rand() % 6 + 1));
    port.addShip(Ship("Athena", "Schuettgut", rand() % 25 + 1, rand() % 6 + 1));

    // Simulation für 24 Stunden
    for (int i = 0; i < 24; ++i) {
        port.advanceTime();
    }

    std::cout << "\n--- Simulation beendet ---\n";
    return 0;
}