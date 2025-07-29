#include <iostream>

using namespace std;

const int DAYS = 7;
const int MAX_MEALS = 10;

int calories[DAYS][MAX_MEALS];
int mealCount[DAYS];

void inputCalories(int calories[][MAX_MEALS], int mealCount[]) {
    for (int day = 0; day < DAYS; ++day) {
        cout << "\nDay " << day + 1 << ". Count ";
        cin >> mealCount[day];

        for (int meal = 0; meal < mealCount[day]; ++meal) {
            cout << "  dinner " << meal + 1 << ": Callories: ";
            cin >> calories[day][meal];
        }
    }
}

void showStatistics(int calories[][MAX_MEALS], int mealCount[]) {
    int totalWeekCalories = 0;
    int totalMeals = 0;
    int maxCalories = 0, minCalories = 0;

    for (int day = 0; day < DAYS; ++day) { 
        for(int meal = 0; meal < mealCount[day]; ++meal) {
            if(calories[day][meal] > maxCalories){
                maxCalories = calories[day][meal];
			}
            if(calories[day][meal] < minCalories || minCalories == 0) {
                minCalories = calories[day][meal];
			}
            totalWeekCalories += calories[day][meal];
            totalMeals++;
		}	
    }
    cout << "total week calories: " << totalWeekCalories << endl;
    cout << "total meals: " << totalMeals << endl;
    cout << "max cal: " << maxCalories << endl;
    cout << "min cal: " << minCalories << endl;
}



int main() {
    int choice;
    do {
        cout << "1. input data for the weak\n";
        cout << "2. Show statistic\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            inputCalories(calories, mealCount);
            break;
        case 2:
            showStatistics(calories, mealCount);
            break;
        case 3:
            cout << "Bye!\n";
            break;
        default:
            cout << "Please, try again.\n";
        }

    } while (choice != 3);
}