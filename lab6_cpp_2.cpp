#include <iostream>
#include <fstream>
using namespace std;
// Функция создания нового массива по заданным правилам из текста задания
// в качестве аргументов принимаем размер массива и указатели на два изначальных массива
int* max_vect(int k, int* a,int* b){
    // объявляем указатель на новый массив размером k
    int* c = new int[k];
    // Инициализируем i значение нового массива максимальным из a[i] и b[i].
    for(int i=0; i<k; i++) {
        c[i] = max(a[i], b[i]);
    }
    return c;
}

int main()
{
    // Инициализируем массивы a и b
    int a[]={1,2,3,4,5,6,7,2};
    int b[]={7,6,5,4,3,2,1,3};
    int kc = sizeof(a)/sizeof(a[0]);
    // Вызываем нашу функцию и выводим полученные значения
    int* c = max_vect(kc, a, b);
    for (int i = 0;i < kc; i++)
        cout << c[i] << " ";
    // Создаем объект ofstream и связываем его с определенным файлом на диске
    ofstream file;
    file.open("arrays.txt");
    //При успешном открытии фала начинаем запись
    if (file.is_open()){
        // Записываем первый массив а
        for (int i=0; i<kc; i++){
            file << a[i] << " ";
        }
        file << "\n";
        // Записываем второй массив b
        for (int i=0; i<kc; i++){
            file << b[i] << " ";
        }
        file << "\n";
        //Записываем вычисленный массив c
        for (int i=0; i<kc; i++){
            file << c[i] << " ";
        }
    }
    file.close();
    delete []c; //Возврат памяти.
    return 0;
}
