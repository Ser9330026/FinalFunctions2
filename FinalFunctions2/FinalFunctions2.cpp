// FinalFunctions2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << '[';
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b]\n";
}

template <typename T>
void fill_arr(T arr[], const int length, T left, T right) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (right + 1 - left) + left;
    }   
}

template <typename T>
void fill_arr2(T arr2[], const int length, T left, T right) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr2[i] = rand() % (right - left) + left;
    }
}

/*Задача 1. 
Создайте шаблонную функцию clear_arr,
которая принимает массив, его длину и ключевое
значение. Функция обнуляет все элементы массива,
которые равны ключевому значению.*/

template <typename T>
void clear_arr(T arr[], const int length, T value) {
        for (int i = 0; i < length; i++) {
        if (arr[i] == value) arr[i] = 0;        
    }
}

/*Задача 2. 
Создайте функцию index_sum, которая
принимает два массива и число-индекс. Функция
должна возвращать сумму элементов массива под
указанным индексом.*/

//template <typename T>
int index_sum(int arr[], int arr2[], const int length, const int length2, int value) {
    //int sum;
       // for (int i = 0; i < length; i++) {
           // if (arr[i] == arr[value] && arr2[i] == arr2[value])
                //sum = arr[i] + arr2[i];
            //return sum;
    return arr[value] + arr2[value];

    }

/*Задача 3. 
Создайте шаблонную функцию
mean_arr, которая находит минимальный и
максимальный элементы массива, после чего
возвращает их среднее арифметическое.*/


double mean_arr(int arr[], const int length) {
    int max = arr[0];
    int min  = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) arr[i] = min;
        if (arr[i] > max) arr[i] = max;
    }
    return (min + max)/2.0;
}

/*Задача 4.
Создайте функцию prime_range, которая
принимает два числа, являющиеся началом и концом 
диапазона. Функция должна вывести все простые числа,
которые входят в переданный диапазон.*/


void prime_range(int A, int B) { 
    int flag;
    while (A < B) {
        flag = 0;
        for (int i = 1; i <= A / 2; i++) {
            if (A % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) A++;
    }
  }

/*Задача 5.
Создайте перегруженную функцию
permute_arr, которая принимает массив любого
размера и его длину, после чего меняет местами его
первую и вторую половины.*/

void permute_arr(int arr[], const int length, int temp) {
    //for (int i = length - 1; i >= 0; i--) {
        //for (int j = 0; j < i; j++) {
            //if (arr[j] > arr[j - 1])
                //std::swap(arr[j], arr[j - 1]);
        //}
    //}
    for (int i = 0; i < length/2; i++) {
        std::swap(arr[length / 2 + i], arr[i]);
    }






}

int main()
{
    setlocale(LC_ALL, "rus");

    int a = 0;
    int b = 50;
    int n;

    const int SIZE = 10;
    int arr[SIZE];



    std::cout << "Создайте массив случайных чисел: ";
    fill_arr(arr, SIZE, a, b);
    print_arr(arr, SIZE);

    std::cout << "Введите ключевое значение: ";
    std::cin >> n;
    clear_arr(arr, SIZE, n);

    std::cout << '\n';

    
    const int SIZE2 = 10;
    int arr2[SIZE2];

    fill_arr(arr, SIZE, a, b);
    print_arr(arr, SIZE);

    fill_arr2(arr2, SIZE2, a, b);
    print_arr(arr2, SIZE2);

    std::cout << "Индекс: ";
    std::cin >> n;
    std::cout << index_sum(arr, arr2, SIZE, SIZE2, n);

    std::cout << '\n';

    std::cout << "Среднее арифметическое массива: ";
    std::cout << mean_arr(arr, SIZE);

    std::cout << '\n';

    int A, B;
    std::cout << "Введите требуемый диапазон: ";
    std::cin >> A >> B;

    std::cout << "Простые числа из указанного диапазона: ";
    prime_range(A, B);

    return 0;
}

