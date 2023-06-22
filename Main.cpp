#include <iostream>
#include "ArrayInt.h"

int main()
{
    int index = 0;
   // проверяем некорректную длину массива
    try {
        ArrayInt zeroArray(index);
    }

    catch (bad_length badlenght)
    {
        std::cerr << badlenght.what();
        LengthCorrector correctLenght; //добавим возможность корректирования длины массива
        index = correctLenght.ManualIndex();
    }

    try // В данном случае все проверки я включил в один блок try, потому что я предполагаю, что при некорректных параметрах
        // контейнер не должен выполняться. Поэтому после обработки исключения прекращается работа.
    {
    // Объявляем массив с 10 элементами
        ArrayInt array(10);
        // Заполняем массив числами от 1 до 10
        for (int i = 0; i < 10; i++)
            array[i] = i + 1;

        // Изменяем размер массива до 7 элементов
        array.resize(7);

        // Вставляем число 15 перед элементом с индексом 4. 
        array.insertBefore(15, 4); //работает, выпадает исключение, если индекс больше длины массива или отрицательный

        // Удаляем элемент с индексом 5
        array.remove(5); // работает, исключение выбрасывается при отрицательных значениях индекса 
                         // и при значениях больше длины массива

        // Добавляем числа 35 и 50 в конец и в начало
        array.insertAtEnd(35);
        array.insertAtBeginning(50);

        // Выводим все элементы массива
        for (int j = 0; j < array.getLength(); j++)
            std::cout << array[j] << " ";
    }
    catch (bad_range& bad)
    {
        std::cerr << bad.what();
    }

    catch (bad_length badlenght)
    {
        std::cerr << badlenght.what();
    }

    return 0;
}