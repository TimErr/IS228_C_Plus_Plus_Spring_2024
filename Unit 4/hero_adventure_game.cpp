#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random> // Include the <random> header for random number generation

// Base class for creatures
class Creature {
protected:
    std::string name;
    int health;
    int attackPower;
public:
    Creature(std::string n, int hp, int ap) : name(n), health(hp), attackPower(ap) {}

    //attack function calculates damage and calls takeDamage 
    virtual void attack(Creature& opponent) {
        int damage = rand() % attackPower + 1;
        opponent.takeDamage(damage);
        std::cout << name << " attacks " << opponent.getName() << " for " << damage << " damage!" << std::endl;
    }

    //takeDamage function calculates new health using damage from attack function
    virtual void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << name << " has been defeated!" << std::endl;
        }
    }

    //heal function will heal creature 25 health points or if less than 25 to maxHealth then heal the difference of health and maxHealth.
    virtual void heal(int amount, int maxHealth) {
        if (health < maxHealth) {
            int amountToHeal = std::min(maxHealth - health, amount); 
            health += amountToHeal;
            std::cout << name << " is healed for " << amountToHeal << " health points! Health is now " << getHealth() << std::endl;
        } else {
            std::cout << name << " is already at full health!" << std::endl;
        }
    }

    //getHealth gets the creatures health point amount
    int getHealth() const {
        return health;
    }

    //getName gets the creatures name (hero or monster)
    std::string getName() const {
        return name;
    }

    //isAlive to determine if creature is still alive, health must be greater than 0
    bool isAlive() const {
        return health > 0;
    }    
};

// Derived class for a player-controlled creature
class Player : public Creature {
private: 
    bool shieldActivated;
public:
    Player(std::string n, int hp, int ap) : Creature(n, hp, ap), shieldActivated(false) {}
    int maxHealth = 100;
    //attack function overrides the parent creature function
    void attack(Creature& opponent) override {
        
        //give list of options to player
        std::cout << "Choose your attack:" << std::endl;
        std::cout << "1. Normal Attack" << std::endl;
        std::cout << "2. Special Attack" << std::endl;
        std::cout << "3. Heal" <<std::endl;
        std::cout << "4. Activate Shield" << std::endl;
        
        //take player choice and perform appropriate action
        int choice;
        std::cin >> choice;
        
        if (choice == 1) {
            Creature::attack(opponent);
        } else if (choice == 2) {
            int damage = rand() % (2 * attackPower) + 1; // Special attack does double damage
            opponent.takeDamage(damage);
            std::cout << name << " performs a special attack on " << opponent.getName() << " for " << damage << " damage!" << std::endl;
        } else if (choice == 3) {
            heal(25, maxHealth); //heals 25 points, but monster also gets to deal damage
        } else if (choice == 4) {
            shieldActivated = true; //use shield to reduce damage
            std::cout << name << " activates shield!" << std::endl;
        }
    }

    //takeDamage function overrides parent Creature function
    void takeDamage(int damage) override {
        if (shieldActivated) {
            std::cout << name << " uses shield and reduces damage by 50%!" <<std::endl;
            damage /= 2; //damage is reduced by 50%
        }
        Creature::takeDamage(damage);
    }
};

// Derived class for an AI-controlled creature
class Enemy : public Creature {
private: 
    bool shieldActivated;
    
public:
    // Modify the constructor to accept a range of health values
    Enemy(std::string n, int minHp, int maxHp, int ap) : Creature(n, generateRandomHealth(minHp, maxHp), ap), shieldActivated(false) {}
    
    int maxHealth;

    // Function to generate a random health value within the specified range
    int generateRandomHealth(int minHp, int maxHp) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minHp, maxHp);
        maxHealth = dis(gen);
        return maxHealth;
    }
    
     //attack function overrides the parent creature function
    void attack(Creature& opponent) override {
        int choice = rand() % 3; // Randomly choose between normal attack, special attack, heal, or use shield

        if (choice == 0) {
            Creature::attack(opponent);
        } else if (choice ==1) {
            int damage = rand() % (2 * attackPower) + 1; // Special attack does double damage
            opponent.takeDamage(damage);
            std::cout << name << " performs a special attack on " << opponent.getName() << " for " << damage << " damage!" << std::endl;
        } else if (choice == 2) {
            heal(25, maxHealth); //heals 25 points, but monster also gets to deal damage
        } else if (choice == 3) {
            shieldActivated = true; //use shield to reduce damage
            std::cout << name << " activates shield!" << std::endl;
        }
    }

    //takeDamage function overrides parent Creature function
    void takeDamage(int damage) override {
        if (shieldActivated) {
            std::cout << name << " uses shield and reduces damage by 50%!" <<std::endl;
            damage /= 2; //damage is reduced by 50%
        }
        Creature::takeDamage(damage);
    }
};

//Function to print the health of each player after each attack sequence.
void printPlayerHealth(const Player& player, const Enemy& enemy){
    std::cout << "Player health: " << player.getHealth() << std::endl;
    std::cout << "Enemy health: " << enemy.getHealth() << std::endl;

}

int main() {
    srand(time(0)); // Seed for random number generation

    Player player("Hero", 100, 20);//creature is of type player name is Hero, health is 100 and attack power is 20
    Enemy enemy("Monster", 25, 125, 15);//creature is of type enemy name is Monster, health is random between 25 and 125, and attack power is 15
    
    int turns = 0; // Initialize turn counter

    //while loop to continue as long as both player and enemy are alive (health > 0)
    while (player.isAlive() && enemy.isAlive()) {
        ++turns;//Increment turn counter
        std::cout << "Turn " << turns << std::endl;//Display Current turn.
        printPlayerHealth(player, enemy);//print health point of each creature
        player.attack(enemy);
        if (!enemy.isAlive()) break;
        enemy.attack(player);
        //printPlayerHealth(player, enemy);//print health point of each creature
    }

    std::cout<<"Total turns taken: " << turns << std::endl;//Display total turns taken 

    return 0;
}