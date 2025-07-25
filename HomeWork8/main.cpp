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

void showMenuOptions()
{
    std::cout << "0. червоний" << std::endl
              << "1. синій" << std::endl
              << "2. зелений" << std::endl
              << "3. жовтий" << std::endl
              << "4. фіолетовий" << std::endl
              << "5. блакитний" << std::endl
              << "6. білий" << std::endl
              << "7. чорний" << std::endl
              << "8. помаранчевий" << std::endl
              << "9. бежевий" << std::endl
              << "10. рожевий" << std::endl
              << "11. салатовий" << std::endl
              << "12. сірий" << std::endl;
}
void showLiklyColors()
{
    if (lovelyColor & redColor)
    {
        std::cout << "0. Полюбяєте червоний" << std::endl;
    }
    if (lovelyColor & blueColor)
    {
        std::cout << "1. Полюбляєте синій" << std::endl;
    }
    if (lovelyColor & greenColor)
    {
        std::cout << "2. Полюбляте зелений" << std::endl;
    }
    if (lovelyColor & yellowColor)
    {
        std::cout << "3. Полюляєте жовтий" << std::endl;
    }
    if (lovelyColor & purpleColor)
    {
        std::cout << "4. Полюбляєте фіолетовий" << std::endl;
    }
    if (lovelyColor & lightBlueColor)
    {
        std::cout << "5. Полюбляєте блакитний" << std::endl;
    }
    if (lovelyColor & whiteColor)
    {
        std::cout << "6. Полубляєте білий" << std::endl;
    }
    if (lovelyColor & blackColor)
    {
        std::cout << "7. Полюбляєте чорний" << std::endl;
    }
    if (lovelyColor & orangeColor)
    {
        std::cout << "8. Полюбляєте помаранчевий" << std::endl;
    }
    if (lovelyColor & beigeColor)
    {
        std::cout << "9. Полюбляєте бежевий" << std::endl;
    }
    if (lovelyColor & pinkColor)
    {
        std::cout << "10. Полюбляєте рожевий" << std::endl;
    }
    if (lovelyColor & ligthGreenColor)
    {
        std::cout << "11. Полюбляєте салатовий" << std::endl;
    }
    if (lovelyColor & greyColor)
    {
        std::cout << "12. Полюбляєте сірий" << std::endl;
    }
}

int main()
{
    int choosenNumber;
    while (true)
    {
        std::cout << "Choose the option" << std::endl
                  << "1. Add favorite colour" << std::endl
                  << "2. Remove favorite" << std::endl
                  << "3. Show favorites" << std::endl
                  << "4. Exit" << std::endl;
        std::cin >> choosenNumber;
        if (choosenNumber > 0 && choosenNumber < 5)
        {
            switch (choosenNumber)
            {
            case 1:
                int optionAdd;
                showMenuOptions();
                std::cin >> optionAdd;
                lovelyColor |= 1 << optionAdd;
                break;
            case 2:
                int optionRemove;
                showMenuOptions();
                std::cin >> optionRemove;
                lovelyColor ^= 1 << optionRemove;
                break;
            case 3:
                showLiklyColors();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Incorrect option" << std::endl;
            }
        }
    }
}