#include <iostream>
constexpr int redColor = 0b1;
constexpr int blueColor = 0b10;
constexpr int greenColor = 0b100;
constexpr int yellowColor = 0b1000;
constexpr int purpleColor = 0b10000;
constexpr int lightBlueColor = 0b100000;
constexpr int whiteColor = 0b1000000;
constexpr int blackColor = 0b10000000;
constexpr int orangeColor = 0b100000000;
constexpr int beigeColor = 0b1000000000;
constexpr int pinkColor = 0b10000000000;
constexpr int ligthGreenColor = 0b100000000000;
constexpr int greyColor = 0b1000000000000;
int lovelyColor = 0;

class ColorsSingleton {
private:
    static ColorsSingleton* m_instance;
    ColorsSingleton() = default;

    ColorsSingleton(ColorsSingleton&) = delete;
    ColorsSingleton& operator=(ColorsSingleton&) = delete;
    ColorsSingleton(ColorsSingleton&&) = delete;
    ColorsSingleton& operator=(ColorsSingleton&&) = delete;
public:
    static ColorsSingleton* instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new ColorsSingleton();
        }
        return m_instance;
    }
    void addColor(const int color) { 
        lovelyColor |= 1 << color;
    }
    void removeColor(const int color) {
        lovelyColor ^= 1 << color;
    }
    bool isFavoriteColor(const int color) {

        if (lovelyColor & 1 << color) {
			return true;
        }
        else {
			return false;
        }

    }
    void showLiklyColors()
    {
        if (lovelyColor & redColor)
        {
            std::cout << "0. You like red" << std::endl;
        }
        if (lovelyColor & blueColor)
        {
            std::cout << "1. You like blue" << std::endl;
        }
        if (lovelyColor & greenColor)
        {
            std::cout << "2. You like green" << std::endl;
        }
        if (lovelyColor & yellowColor)
        {
            std::cout << "3. You like yellow" << std::endl;
        }
        if (lovelyColor & purpleColor)
        {
            std::cout << "4. You like purple" << std::endl;
        }
        if (lovelyColor & lightBlueColor)
        {
            std::cout << "5. You like light blue" << std::endl;
        }
        if (lovelyColor & whiteColor)
        {
            std::cout << "6. You like white" << std::endl;
        }
        if (lovelyColor & blackColor)
        {
            std::cout << "7. You like black" << std::endl;
        }
        if (lovelyColor & orangeColor)
        {
            std::cout << "8. You like orange" << std::endl;
        }
        if (lovelyColor & beigeColor)
        {
            std::cout << "9. You like beige" << std::endl;
        }
        if (lovelyColor & pinkColor)
        {
            std::cout << "10. You like pink" << std::endl;
        }
        if (lovelyColor & ligthGreenColor)
        {
            std::cout << "11. You like ligth green" << std::endl;
        }
        if (lovelyColor & greyColor)
        {
            std::cout << "12. You like grey" << std::endl;
        }
    }
    void showMenuOptions()
    {
        std::cout << "0. red" << std::endl
            << "1. blue" << std::endl
            << "2. green" << std::endl
            << "3. yellow" << std::endl
            << "4. purple" << std::endl
            << "5. light blue" << std::endl
            << "6. white" << std::endl
            << "7. black" << std::endl
            << "8. orange" << std::endl
            << "9. beige" << std::endl
            << "10. pink" << std::endl
            << "11. light green" << std::endl
            << "12. grey" << std::endl;
    }
};

ColorsSingleton* ColorsSingleton::m_instance = nullptr;


int main()
{
    int choosenNumber;
    while (true)
    {
        std::cout << "Choose the option" << std::endl
                  << "1. Add favorite colour" << std::endl
                  << "2. Remove favorite" << std::endl
                  << "3. Show favorites" << std::endl
                  << "4. Check the color" << std::endl
                  << "5. Exit" << std::endl;
        std::cin >> choosenNumber;
        if (choosenNumber > 0 && choosenNumber < 6)
        {
            switch (choosenNumber)
            {
            case 1:
                int optionAdd;
				ColorsSingleton::instance()->showMenuOptions();
                std::cin >> optionAdd;
				ColorsSingleton::instance()->addColor(optionAdd);
                break;
            case 2:
                int optionRemove;
                ColorsSingleton::instance()->showMenuOptions();
                std::cin >> optionRemove;
                ColorsSingleton::instance()->removeColor(optionRemove);
                break;
            case 3:
				ColorsSingleton::instance()->showLiklyColors();
                break;
			case 4:
                int optionCheck;
                ColorsSingleton::instance()->showMenuOptions();
				std::cin >> optionCheck;
                if (ColorsSingleton::instance()->isFavoriteColor(optionCheck))
                {
                    std::cout << "You like this color" << std::endl;
                }
                else
                {
                    std::cout << "You don't like this color" << std::endl;
                }
				break;
            case 5:
                return 0;
            default:
                std::cout << "Incorrect option" << std::endl;
            }
        }
    }
}