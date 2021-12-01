#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void M(int* a, const int size, int& min, int i);

int main()
{
    srand((unsigned)time(NULL));
    int n = 0;  
    cout << "N = "; cin >> n;
    int* a = new int[n];
    int Low = -10;
    int High = 10;
    int min = 0;
    int r = 0;
  
    

    Create(a, n, Low, High, 0);
    cout << "a = "; Print(a, n, 0);

    M(a, n, min, 0);
    cout << "min = " << min << endl;
}

void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void M(int* a, const int size, int& min, int i) {
    if (a[i] < min && i % 2 == 0) {
        if (a[i] < min)
            min = a[i];
    }
    if (i < size - 1)
        return M(a, size, min, i + 1);
}

