//
// Created by emilf on 07.07.2025.
//
#ifndef PORT_H
#define PORT_H

#include "Ship.h"
#include <queue>
#include <vector>

class Port {
private:
    std::queue<Ship> waitingQueue;          // Warteschlange für Schiffe
    std::vector<Ship> processedShips;       // Liste der abgefertigten Schiffe
    Ship* shipAtDock;                       // Zeiger auf das Schiff am Dock
    int currentHour;                        // Aktuelle Stunde der Simulation
    bool badWeather;                        // Gibt an, ob schlechtes Wetter herrscht

    // Zufallsereignisse
    bool isBadWeather();                    // 20% Wahrscheinlichkeit für Sturm
    int calculateDelay();                   // 15% Wahrscheinlichkeit für Verzögerung

public:
    Port();                                 // Konstruktor
    void addShip(const Ship& newShip);      // Fügt ein Schiff hinzu
    void advanceTime();                     // Simuliert eine Stunde
    void displayStatus();                   // Zeigt aktuellen Status
};

#endif