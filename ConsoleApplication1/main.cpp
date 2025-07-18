#include <iostream>
#include <vector>
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "7.h"
#include "8.h"
#include "9.h"
#include "10.h"
#include "11.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int (*)()> tasks = {
        task1,
        task2,
        task3,
        task4,
        task5,
        task6,
        task7,
        task8,
        task9,
        task10,
        task11,
        
    };

    int choice;
    std::cout << "Выберите номер задачи (от 1 до " << tasks.size() << "): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(tasks.size()))
    {
        std::cout << "Выполнение задачи " << choice << ":\n";
        tasks[choice - 1]();  
    }
    else
    {
        std::cout << "Неверный номер задачи.\n";
    }

    return 0;
}
