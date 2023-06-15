#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

//Структура матрёшка
struct pointer
{
    int d;      //Вводимые данные
    pointer *p; //Указатель на предыдущий элемент стурктуры pointer
};

pointer *initialQueue(int data);     //Инициализация очереди
void AddQueue(pointer **pe, int d);  //Добавление в очередь
int  DeleteQueue(pointer **pb);      //Удаление из очереди

int main()
{
    setlocale(LC_ALL, "rus");

    int data = 0; //Переменная для ввода
    int i = 1;    //Счётчик 

    cout << "Формирование очереди" << endl;
    cout << "Комонент " << i << " -> ";
    //Ввод первого элемента
    cin >> data;   
    //Инициализация очереди
    pointer *pb = initialQueue(data);
    //Указатель конца на начало очереди, так как только один элемент
    pointer *pe = pb;

    cout << "Добавление очереди" << endl;
    do
    {
        i++;                                   //Счетчик элементов 

        if (i >= 6)                         
        {
            cout << "Компонент " << i << " -> ";
            cin >> data;
            AddQueue(&pe, data);
            cout << "Выходит -> " << DeleteQueue(&pb) << endl;
        }
        else if (i <= 5)
        {
            cout << "Компонент " << i << " -> ";
            cin >> data;                           //Ввод данных
            AddQueue(&pe, data);                   //Добавление элемента data в конец очереди по адресу pe
        }
    } 
    while (data != 0);                         //Окончание по вводу 0

    cout << "Вывод очереди на экран" << endl;
    i = 0;                                     //Сброс счетчика для вывода
    while (pb != NULL)                         //Пока не дойдет до дна 
    {
        i++;                                   //Перебор элементов
        cout << "Компонент " << i << " -> " 
            << DeleteQueue(&pb) << endl;       //Перевод указателя на следующий и вывод
    }
    _getch();

    return 0;
}

//Инициализация очереди
pointer * initialQueue(int d)        //Принимаем число, возвращаем адрес px
{
    pointer *px = new pointer; //Создаём указатель px типа pointer
    px->d = d;                 //Присваиваем в int d принимаемое число
    px->p = NULL;              //Присваиваем в px пустое значение, для последующего присвоения адреса
    return px;                 //Возвращаем структуру px
}

void AddQueue(pointer **pe, int d) //Принимаем адрес указателя pe типа pointer и данные для добавления d
{
    pointer *px = new pointer;   //Создаем указатель px типа pointer
    px->d = d;                   //Записываем в переменную d стурктуры px вводимые данные
    px->p = NULL;                //Резервируем место для адреса следющего указателя
    //Записываем в основной указатель pe данные вспомогательного указателя px 
    (*pe)->p = px;              
    (*pe) = px;
}

int DeleteQueue(pointer **pb)    //Принимаем указатель структуры pb(начало очереди)
{
    int d = (*pb)->d;        //Передаем во временную переменную d данные d переменной pb типа pointer
    (*pb) = (*pb)->p;        //Передаем в переменную pb типа pointer адрес следующего указателя
    return d;                //Возвращаем данные для вывода на экран
}