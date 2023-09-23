#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Создаем объект ofstream и связываем его с определенным файлом на диске
    ofstream out;
    out.open("poem.txt");
    if (out.is_open())
    {
        cout << "Enter poem text:" << endl;
        string s;
        // В строку s записываем введенное пользователем значение, если строка пуста - выходим из цикла
        // иначе записываем строку в файл
        while(getline(cin, s)){
            if(s.empty()){
                break;
            }
            out << s << "\n";
        }
    out.close();
    cout << "File has been written" << endl;
    }
}