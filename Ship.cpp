//
// Created by emilf on 17.07.2025.
//

#include "Ship.h"
//
// Created by emilf on 07.07.2025.
//

#include "Ship.h"

// Initialisiert ein Schiff mit den gegebenen Werten
Ship::Ship(std::string n, std::string t, int arrival, int duration)
    : name(n), cargoType(t), arrivalTime(arrival), unloadingDuration(duration),
      extraDelay(0), currentlyUnloading(false) {}
