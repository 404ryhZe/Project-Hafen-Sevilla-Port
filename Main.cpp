// Created by emilf on 07.07.2025.
//
#include "Port.h"              // Einbindung der Header-Datei für die Port-Klasse
#include <iostream>            // Für Ein- und Ausgabe
#include <ctime>               // Für Zeitfunktionen (z. B. zur Initialisierung des Zufallsgenerators)

int main()
{
    // Initialisiert den Zufallsgenerator mit der aktuellen Zeit als Seed
    srand(static_cast<unsigned>(time(0)));

    // Erstellt ein Port-Objekt
    Port port;

    // Fügt dem Hafen drei beispielhafte Schiffe mit zufälliger Ankunftszeit und Liegezeit hinzu
    port.addShip(Ship("Poseidon", "Container", rand() % 25 + 1, rand() % 6 + 1));
    port.addShip(Ship("Neptune", "Gas", rand() % 25 + 1, rand() % 6 + 1));
    port.addShip(Ship("Athena", "Schuettgut", rand() % 25 + 1, rand() % 6 + 1));

    // Simuliert den Ablauf von 24 Stunden im Hafen
    for (int i = 0; i < 24; ++i) {
        port.advanceTime(); // Fortschreiten der Zeit um eine Stunde
    }

    // Gibt eine Abschlussmeldung aus
    std::cout << "\n--- Simulation beendet ---\n";
    return 0;
}
