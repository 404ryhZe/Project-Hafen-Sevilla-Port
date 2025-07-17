//
// Created by emilf on 07.07.2025.
//

#ifndef SHIP_H
#define SHIP_H

#include <string>

// Repräsentiert ein Schiff mit seinen Eigenschaften
class Ship {
public:
    std::string name;                       // Name des Schiffs
    std::string cargoType;                  // Art der Ladung
    int arrivalTime;                        // Ankunftszeit im Hafen (Stunde)
    int unloadingDuration;                  // Dauer des Entladens in Stunden
    int extraDelay;                         // Zusätzliche Verzögerung
    bool currentlyUnloading;                // Wird gerade entladen?

    // Konstruktor
    Ship(std::string n, std::string t, int arrival, int duration);
};

#endif