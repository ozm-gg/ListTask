#include <iostream>
#include "List.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Lessons::List<int> list;
    int input;
int inputValue;
    int elemValue;
    std::cout<<"1 - Добавить в начало\n"
               "2 - Добавить в конец\n"
               "3 - Добавить перед\n"
               "4 - Добавить после\n"
               "5 - Убрать из начала\n"
               "6 - Убрать с конца\n"
               "7 - Убрать заданный\n"
               "8 - Вывести список\n"
               "9 - Посчитать кол-во эл-тов с заданным значением\n";
    while (std::cin >> input) {

        switch (input) {
            case 0:
                return 0;
            case 1:
                std::cin>>inputValue;
                list.PushFront(inputValue);
                break;
            case 2:
                std::cin>>inputValue;
                list.PushBack(inputValue);
                break;
            case 3:
                std::cin>>inputValue;
                std::cin>>elemValue;
                list.PushBefore(elemValue, inputValue);
                break;
            case 4:
                std::cin>>inputValue;
                std::cin>>elemValue;
                list.PushAfter(elemValue, inputValue);
                break;
            case 5:
                std::cout<<list.PopFront()<<std::endl;
                break;
            case 6:
                std::cout<<list.PopBack()<<std::endl;
                break;
            case 7:
                std::cin>>elemValue;
                std::cout<<list.PopCurrent(elemValue)<<std::endl;
                break;
            case 8:
                for (int i = 0; i < list.GetSize(); ++i) {
                    std::cout<<list[i]<<"\t";
                }
                std::cout<<std::endl;
                break;
            case 9:
                std::cin>>elemValue;
                std::cout<<list.CountElementWithValue(elemValue)<<std::endl;
                break;
        }
    }
    return 0;
}
