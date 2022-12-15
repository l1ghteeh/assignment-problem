#include <iostream>
#include <cmath>

using namespace std;
int sum = 0;

int a[4][4]{
{1, 1, 3, 2},
{2, 1, 1, 3},
{1, 1, 3, 3},
{2, 3, 1, 1} };


int menu()
{
    cout << endl;
    cout << "                                 MENU                                                           \n";
    cout << "1. Вывести матрицу" << endl;
    cout << "2. Выполнить задачу" << endl;
    cout << "3. Вывести ответ" << endl;
    cout << "4. Выход" << endl;
    cout << endl;
    int m;
    cin >> m;
    return m;
}
struct naznach {
    int sum1;
    int sum2;
    int sum3;
    int sum4;
};


int show()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    return (0);
}


int work_left_down()
{
    int f = a[0][0], f1 = 0, s = a[1][0], s1 = 1, t = a[2][0], t1 = 2, fo = a[3][0], fo1 = 3;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                if (f > (a[0][j])) { f = a[0][j]; f1 = j; }
            }

            if (i == 1)
            {
                if (s > (a[1][j]) && (j != f1)) { s = a[1][j]; s1 = j; }
            }

            if (i == 2)
            {
                if (t > (a[2][j]) && (j != f1) && (j != s1)) { t = a[2][j]; t1 = j; }
            }

            if (i == 3)
            {
                if (fo > (a[3][j]) && (j != f1) && (j != s1) && (j != t1)) { fo = a[3][j]; fo1 = j; }
            }
        }
    }
    int sum1 = f + s + t + fo;
    cout << endl << sum1 << endl;
    return(sum1);
}
int work_right_down()
{
    int f = a[0][3], f1 = 1, s = a[1][3], s1 = 1, t = a[2][3], t1 = 1, fo = a[3][3], fo1 = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 0; j--) {
            if (i == 0)
            {
                if (f > (a[0][j])) { f = a[0][j]; f1 = j; }
            }

            if (i == 1)
            {
                if (s > (a[1][j]) && (j != f1)) { s = a[1][j]; s1 = j; }
            }

            if (i == 2)
            {
                if (t > (a[2][j]) && (j != f1) && (j != s1)) { t = a[2][j]; t1 = j; }
            }

            if (i == 3)
            {
                if (fo > (a[3][j]) && (j != f1) && (j != s1) && (j != t1)) { fo = a[3][j]; fo1 = j; }
            }
        }
    }
    int sum2 = f + s + t + fo;
    cout << sum2 << endl;
    return(sum2);
}
int work_right_up()
{
    int f = a[0][3], f1 = 3, s = a[1][3], s1 = 2, t = a[2][3], t1 = 1, fo = a[3][3], fo1 = 0;
    for (int i = 3; i > -1; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (i == 0)
            {
                if (f > (a[0][j]) && (j != fo1) && (j != s1) && (j != t1)) { f = a[0][j]; f1 = j; }
            }

            if (i == 1)
            {
                if (s > (a[1][j]) && (j != fo1) && (j != t1)) { s = a[1][j]; s1 = j; }
            }

            if (i == 2)
            {
                if (t > (a[2][j]) && (j != fo1)) { t = a[2][j]; t1 = j; }
            }

            if (i == 3)
            {
                if (fo > (a[3][j])) { t = a[3][j]; fo1 = j; }
            }
        }
    }
    int sum3 = f + s + t + fo;
    cout << sum3 << endl;
    return(sum3);
}
int work_left_up()
{
    int f = a[0][0], f1 = 0, s = a[1][0], s1 = 1, t = a[2][0], t1 = 2, fo = a[3][0], fo1 = 3;
    for (int i = 3; i > -1; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                if (f > (a[0][j]) && (j != fo1) && (j != s1) && (j != t1)) { f = a[0][j]; f1 = j; }
            }

            if (i == 1)
            {
                if (s > (a[1][j]) && (j != fo1) && (j != t1)) { s = a[1][j]; s1 = j; }
            }

            if (i == 2)
            {
                if (t > (a[2][j]) && (j != fo1)) { t = a[2][j]; t1 = j; }
            }

            if (i == 3)
            {
                if (fo > (a[3][j])) { fo = a[3][j]; fo1 = j; }
            }
        }
    }
    int sum4 = f + s + t + fo;
    cout << sum4 << endl;
    return(sum4);
}

int answer(int sum1, int sum2, int  sum3, int sum4)
{
    int sum = 0;
    if ((sum1 <= sum2) && (sum1 <= sum3) && (sum1 <= sum4)) sum = sum1; else
        if ((sum2 <= sum1) && (sum2 <= sum3) && (sum2 <= sum4)) sum = sum2; else
            if ((sum3 <= sum1) && (sum3 <= sum2) && (sum3 <= sum4)) sum = sum3; else
                if ((sum4 <= sum1) && (sum4 <= sum2) && (sum4 <= sum3)) sum = sum4;
    cout << endl << "Лучшее распределение = " << sum;
    return(0);
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "КУРСОВАЯ РАБОТА:\n" << "Попов Юрий\n" << "15.11Д - МО12/20б\n";
    cout << "Тема: Задача о назначениях\n" << endl;
    bool access = 0;
    cout << "Начать работу? 1.ДА 0.НЕТ " << endl;
    cin >> access;
    while (access == 1)
        switch (menu())
        {
        case 1:
        {
            cout << "Матрица, где каждая строка работник,столбец задача, цифра уровень выполнения:" << endl;
            int swohrun(show());
            break;
            menu();
        }
        case 2:
        {
            work_left_down();
            work_right_down();
            work_right_up();
            work_left_up();
            break;
            menu();
        }
        case 3:
        {
            answer(work_left_down(),
                work_right_down(),
                work_right_up(),
                work_left_up());
            break;
            menu();
        }
        case 4: cout << "Завершить программу? 1. Да 2. Нет" << endl;
        {int e;
        cin >> e;
        if (e == 1) exit(e); else
            break;
        menu();
        }
        }
}
