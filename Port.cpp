//
// Created by emilf on 07.07.2025.
//

#include "Port.h"
#include <iostream>
#include <cstdlib>

Port::Port() : shipAtDock(nullptr), currentHour(0), badWeather(false) {}

// Fügt ein Schiff zur Warteschlange hinzu
void Port::addShip(const Ship& newShip) {
    waitingQueue.push(newShip);
}

// Simuliert eine Stunde im Hafenbetrieb
void Port::advanceTime() {
    currentHour++;
    badWeather = isBadWeather(); // Wetter aktualisieren

    std::cout << "\n--- Stunde " << currentHour << " ---\n";
    displayStatus();

    // Wenn ein Schiff am Dock ist
    if (shipAtDock != nullptr) {
        // Entladedauer reduzieren
        shipAtDock->unloadingDuration--;

        // Wenn Entladen abgeschlossen ist
        if (shipAtDock->unloadingDuration <= 0) {
            std::cout << "Schiff " << shipAtDock->name << " hat das Entladen abgeschlossen und dockt ab vom Dock.\n";
            processedShips.push_back(*shipAtDock);
            delete shipAtDock;
            shipAtDock = nullptr;
        }
    }

    // Wenn kein Schiff am Dock und kein Sturm
    if (shipAtDock == nullptr && !badWeather && !waitingQueue.empty()) {
        Ship nextShip = waitingQueue.front();
        waitingQueue.pop();

        // Verzoegerung berechnen
        int delay = calculateDelay();
        nextShip.extraDelay = delay;
        nextShip.unloadingDuration += delay;
        nextShip.currentlyUnloading = true;

        shipAtDock = new Ship(nextShip);
        std::cout << "Schiff " << shipAtDock->name << " Dockt am Dock an und beginnt mit dem Entladen.\n";
        if (delay > 0) {
            std::cout << "Verzoegerung: " << delay << " Stunden.\n";
        }
    }
}

// Gibt den aktuellen Status des Hafens aus
void Port::displayStatus() {
    std::cout << "Wetter: " << (badWeather ? "Sturm" : "Klar") << "\n";

    if (shipAtDock != nullptr) {
        std::cout << "Am Dock: " << shipAtDock->name
                  << " (" << shipAtDock->cargoType << "), verbleibende Zeit: "
                  << shipAtDock->unloadingDuration << " Stunden\n";
    } else {
        std::cout << "Kein Schiff am Dock.\n";
    }

    std::cout << "Wartende Schiffe: " << waitingQueue.size() << "\n";
}

// 20% Wahrscheinlichkeit für schlechtes Wetter
bool Port::isBadWeather() {
    int prob = rand() % 100;
    return (prob < 20);
}

// 15% Wahrscheinlichkeit für Verzoegerung (1–3 Stunden)
int Port::calculateDelay() {
    int prob = rand() % 100;
    if (prob < 15)
        return rand() % 3 + 1;
    return 0;
}