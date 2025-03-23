#include <iostream>
#include <string>

int main() 
{
    float redPotion{0.0f}; 
    float bluePotion{0.0f};
    float* flask{nullptr}; 

    
    while (true)
    {
        std::cout << "Which potion to add liquid to (Red, Blue)? Type 'Done' to finish." << std::endl;
        std::string potion;
        std::cin >> potion;

        if (potion == "Red" || potion == "red")
        {
            flask = &redPotion; 
        }
        else if (potion == "Blue" || potion == "blue")
        {
            flask = &bluePotion; 
        }
        else if (potion == "Done" || potion == "done")
        {
            break; 
        }
        else
        {
            std::cout << "Invalid potion color. Please enter 'Red' or 'Blue'." << std::endl;
            continue;
        }

        std::cout << "How many milliliters to add?" << std::endl;
        float milliliters;
        std::cin >> milliliters;
       
        *flask += milliliters;

        std::cout << "Red Potion: " << redPotion << " ml" << std::endl;
        std::cout << "Blue Potion: " << bluePotion << " ml" << std::endl;
    }

    std::cout << "Brewing complete!" << std::endl;
    return 0;
}
