/*
Задания для самостоятельного выполнения.
Выполнение заданий осуществляется без использования библиотеки STL.
Создать шаблонный класс NameClass<T> и публичную вложенную
структуру Node (имя класса указано в задании). Данный класс должен быть
объявлен и определен в пространстве имен containers.
Структура Node должна содержать:
 Публичное поле value типа T со значением, хранимым в данном
элементе шаблонного класса.
 Приватные поля для осуществления связи элементов в шаблонном
классе.
 Приватный конструктор(ы). Ничто кроме шаблонного класса
NameClass не должно иметь возможности создания элементов типа Node.
Класс должен содержать:
 конструктор по умолчанию, создающий экземпляр класса нулевого
размера;
 Конструктор от std::initializer_list<T>.
 Конструктор копирования и копирующий оператор присваивания.
 Конструктор перемещения и перемещающий оператор присваивания.
 операцию индексирования, возвращающую ссылку на
соответствующий элемент экземпляра класса;
 метод, добавляющий элемент в произвольную позицию экземпляра
класса;
 метод, удаляющий элемент из конца экземпляра класса (начала,
произвольный элемент (в зависимости от задания)).
Добавить в класс другие методы, необходимые для реализации
задания. При выборе методов ориентироваться на методы, которые есть у
шаблонных классов библиотеки STL.
В клиенте main() продемонстрировать использование этого класса для
векторов, содержащих элементы типов int, double, string.
Для этого написать программу, демонстрирующую работу с этим
шаблоном для различных типов параметров шаблона. Программа должна
содержать меню, позволяющее осуществить проверку всех методов шаблона.
Задание.
Вариант 9.
Создать шаблон класса «двунаправленный кольцевой список» (DRList).
*/

#include <iostream>
#include <string>
#include "DRList.h"
#include <vector>

containers::DRList<int> foo(containers::DRList<int> x) {
    return x;
}

int main() {
    // Создаём DRList с элементами типа int
    containers::DRList<int> intList;

    // Добавляем элементы в начало
    intList.addElement(0, 0);

    // Добавляем элемент в произвольную позицию (после первого элемента)
    intList.addElement(4, 1);

    // Добавляем элементы в конец
    intList.addElement(8, 2);
    intList.addElement(7, 3);

    // Удаляем элемент из конца
    intList.removeElement();

    // Выводим элементы
    std::cout << "Int List: ";
    for (int i = 0; i < intList.getSize(); ++i) {
        std::cout << intList[i] << " ";
    }
    std::cout << std::endl;

    // Создаём DRList с элементами типа double
    containers::DRList<double> doubleList;

    // Добавляем элементы в конец
    doubleList.addElement(1.1, 0);
    doubleList.addElement(2.2, 1);
    doubleList.addElement(3.3, 2);

    // Выводим элементы
    std::cout << "Double List: ";
    for (int i = 0; i < doubleList.getSize(); ++i) {
        std::cout << doubleList[i] << " ";
    }
    std::cout << std::endl;

    // Создаём DRList с элементами типа string
    containers::DRList<std::string> stringList;

    // Добавляем элементы в конец
    stringList.addElement("Hello", 0);
    stringList.addElement("World", 1);

    // Выводим элементы
    std::cout << "std::string List: ";
    for (int i = 0; i < stringList.getSize(); ++i) {
        std::cout << stringList[i] << " ";
    }

    std::cout << std::endl << std::endl;

    // Создаём DRList с элементами типа int
    containers::DRList<int> intList2 = { 1, 3, 5, 7 };

    // Выводим элементы 
    std::cout << "Int List: ";
    for (int i = 0; i < intList2.getSize(); ++i) {
        std::cout << intList2[i] << " ";
    }
    std::cout << std::endl;

    // Создаём DRList с элементами типа double
    containers::DRList<double> doubleList2 = { 1, 2, 6, 8 };

    // Выводим элементы 
    std::cout << "Double List: ";
    for (int i = 0; i < doubleList2.getSize(); ++i) {
        std::cout << doubleList2[i] << " ";
    }
    std::cout << std::endl;

    // Создаём DRList с элементами типа std::string
    containers::DRList<std::string> stringList2 = { "Hello", "world"};

    // Выводим элементы 
    std::cout << "std::string List: ";
    for (int i = 0; i < stringList2.getSize(); ++i) {
        std::cout << stringList2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Конструктор копирования (intList -> intListCopy)
    containers::DRList<int> intListCopy{ intList };
    std::cout << std::endl;
    std::cout << "Copy constructor (int): ";
    for (int i = 0; i < intListCopy.getSize(); ++i)
    {
        std::cout << intListCopy[i] << " ";
    }
    
    std::cout << std::endl << std::endl;

    // Конструктор перемещения (intListMoveTest -> intListMove)
    containers::DRList<int> intListMoveTest{ 1, 9, 6, 8 };

    containers::DRList<int> intListMoveTest1;

    intListMoveTest1 = foo(intListMoveTest);

    std::cout << std::endl;

    system("pause");
    return 0;
}
