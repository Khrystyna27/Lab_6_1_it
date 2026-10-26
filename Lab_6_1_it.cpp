// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним способом
// Варіант 30
 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// Заповнює масив випадковими числами з діапазону [Low; High].
// a - масив; size - кількість елементів;
// Low, High - межі діапазону значень (параметри-значення)
void Create(int* a, const int size, const int Low, const int High)
{
   for (int i = 0; i < size; i++)
       a[i] = Low + rand() % (High - Low + 1);
}
 
// Виводить елементи масиву в один рядок (кожен елемент - 4 позиції).
// a - масив; size - кількість елементів
void Print(int* a, const int size)
{
   for (int i = 0; i < size; i++)
       cout << setw(4) << a[i];
   cout << endl;
}
 
// Критерій відбору: число додатне і парне.
// x - значення елемента масиву
bool Criterion(const int x)
{
   return x > 0 && x % 2 == 0;
}
 
// Повертає кількість елементів масиву, що задовольняють критерію.
// a - масив; size - кількість елементів
int Count(int* a, const int size)
{
   int k = 0; // лічильник елементів
   for (int i = 0; i < size; i++)
       if (Criterion(a[i]))
           k++;
   return k;
}
 
// Повертає суму елементів масиву, що задовольняють критерію.
// a - масив; size - кількість елементів
int Sum(int* a, const int size)
{
   int s = 0; // сума елементів
   for (int i = 0; i < size; i++)
       if (Criterion(a[i]))
           s += a[i];
   return s;
}
 
// Замінює нулями елементи масиву, що задовольняють критерію.
// a - масив (параметр-посилання за суттю); size - кількість елементів
void ZeroCriterion(int* a, const int size)
{
   for (int i = 0; i < size; i++)
       if (Criterion(a[i]))
           a[i] = 0;
}
 
int main()
{
   srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
 
   const int n = 25;    // кількість елементів масиву
   const int Low = -20; // нижня межа діапазону значень
   const int High = 30; // верхня межа діапазону значень
   int a[n];
 
   Create(a, n, Low, High);
   cout << "Початковий масив:" << endl;
   Print(a, n);
 
   cout << "Кількість елементів (додатні парні) = " << Count(a, n) << endl;
   cout << "Сума елементів (додатні парні) = " << Sum(a, n) << endl;
 
   ZeroCriterion(a, n);
   cout << "Модифікований масив:" << endl;
   Print(a, n);
 
   return 0;
}

