#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>

// Cross-platform screen clear
void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

// Cross-platform sleep
void sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// Flower class
class Flower {
public:
    std::string name;
    int waterLevel;
    int growthStage;

    Flower(const std::string &name) : name(name), waterLevel(50), growthStage(0) {}

    void water() {
        waterLevel = std::min(waterLevel + 20, 100);
        std::cout << "\033[1;34mYou watered the " << name << "! Water level is now " << waterLevel << ".\033[0m\n";
    }

    void grow() {
        if (waterLevel > 30) {
            growthStage = std::min(growthStage + 1, 5);
            waterLevel -= 20;
        } else {
            std::cout << "\033[1;31mThe " << name << " needs more water to grow!\033[0m\n";
        }
    }

    std::string getGrowthArt() const {
        if (growthStage == 0) return "    .\n";
        if (growthStage == 1) return "    .\n    |   🌱\n";
        if (growthStage == 2) return "    .\n   /|\\   🌱\n";
        if (growthStage == 3) return "    🌼\n   /|\\\n";
        if (growthStage == 4) return "   🌸\n   /|\\   🌱\n";
        return " 🌻\n  /|\\  Fully Grown!\n";
    }

    void displayStatus() const {
        std::cout << "\033[1;33m" << name << " Status:\033[0m\n";
        std::cout << getGrowthArt();
        std::cout << "\033[1;36mWater Level: [" << std::string(waterLevel / 10, '=') 
                  << std::string(10 - waterLevel / 10, ' ') << "] " << waterLevel << "/100\033[0m\n";
        std::cout << "\033[1;35mGrowth Stage: " << growthStage << "/5\033[0m\n";
    }
};

// Main garden class
class Garden {
private:
    std::vector<Flower> flowers;

public:
    void addFlower(const std::string &flowerName) {
        flowers.emplace_back(flowerName);
        std::cout << "\033[1;32mYou planted a " << flowerName << "!\033[0m\n";
    }

    void waterFlowers() {
        for (auto &flower : flowers) {
            flower.water();
        }
    }

    void growFlowers() {
        for (auto &flower : flowers) {
            flower.grow();
        }
    }

    void displayGarden() const {
        clearScreen();
        if (flowers.empty()) {
            std::cout << "\033[1;31mYour garden is empty. Plant some flowers!\033[0m\n";
            return;
        }

        std::cout << "\033[1;36m=== Your Beautiful Garden ===\033[0m\n";
        for (const auto &flower : flowers) {
            flower.displayStatus();
            std::cout << "-------------------------\n";
        }
    }
};

// Menu
void showMenu() {
    std::cout << "\033[1;33mChoose an action:\033[0m\n";
    std::cout << "\033[1;32m1. Plant a Flower\033[0m\n";
    std::cout << "\033[1;34m2. Water the Garden\033[0m\n";
    std::cout << "\033[1;35m3. Let the Flowers Grow\033[0m\n";
    std::cout << "\033[1;31m4. Exit\033[0m\n";
    std::cout << "\033[1;36mEnter your choice: \033[0m";
}

int main() {
    Garden garden;

    while (true) {
        garden.displayGarden();
        showMenu();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\033[1;36mEnter the name of the flower: \033[0m";
            std::string flowerName;
            std::cin >> flowerName;
            garden.addFlower(flowerName);
        } else if (choice == 2) {
            garden.waterFlowers();
        } else if (choice == 3) {
            garden.growFlowers();
        } else if (choice == 4) {
            std::cout << "\033[1;35mGoodbye! Thanks for tending to your garden!\033[0m\n";
            break;
        } else {
            std::cout << "\033[1;31mInvalid choice! Try again.\033[0m\n";
        }
hello
I'll start coding as soon.as possible I'm really sorry fr
        sleep(1500);
    }

    return 0;
}
