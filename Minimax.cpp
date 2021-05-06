// Minimax.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int res[4][3] = {
    {100, 30, 2},
    {1000, 0, -100},
    {20, 50, 40},
    {42, 50, 1000}
};
int sum = 0;
int step = 0;
int input = 0;
bool IsFinal(int sotep) {
    if (sotep < 4) return false;
    return true;
}
int min(int a, int b) {
    if (a > b) return b;
    return a;
}
int max(int a, int b) {
    if (a > b) return a;
    return b;
}
int minimax(int Step = 0, int Sum = 0, bool maxplayer = true) {
    int bestvalue = maxplayer ? -10000 : 10000;
    int bestStep = 0;
    for (int i = 1; i < 4; i++) {
        int oldBest = bestvalue;
        if (maxplayer) {
            if (IsFinal(Step + i)) bestvalue = max(bestvalue, res[Step][i - 1]);
            else {
                bestvalue = max(bestvalue, minimax(Step + i, res[Step][i - 1], !maxplayer));
                //cout << "minimax()" << endl;
            }
        }
        else {
            if (IsFinal(Step + i)) bestvalue = min(bestvalue, res[Step][i - 1]);
            else {
                bestvalue = min(bestvalue, minimax(Step + i, res[Step][i - 1], !maxplayer));
                //cout << "minimax()" << endl;
            }
        }
        if (oldBest != bestvalue) bestStep = i;
    }
    //cout << Step << ' ' << res[Step][bestStep-1] << ' ' << bestStep << ' ' << Sum << ' ' << bestvalue << endl;
    return Sum + bestvalue;
}
int main()
{
    while (step < 4) {
        cout << res[step][0] << ' ' << res[step][1] << ' ' << res[step][2] << endl;
        //cin >> input;
        //sum += res[step][input-1];
        step += 1;
    }
    //cout << sum << endl;
    int testStep = 0;
    cout << minimax(testStep, 0, true) << endl;
    cout << minimax(testStep, 0, false) << endl;
    cin >> testStep;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
