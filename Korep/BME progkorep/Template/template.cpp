#include <iostream>

using namespace std;

//template-ekben változóként adjuk meg a típust, így több típusra is működik

template <class T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
    //Errort csak akkor kaphatunk, amikor használjuk konkrét instanceben, és olyan típust
    //kap, ami nem működik.
}

//osztályokra is használhatjuk, persze, aminek van értelme ha bizonyos adatszerkezeteket írunk


template <class T, int n>
class sequence
{
    T items[n];
public:
    void setItem(T item, int index);
    T getItem(int index);
};

template <class T, int n>
void sequence<T,n>::setItem(T item, int index) {
    items[index] = item;
} 

template <class T, int n>
T sequence<T,n>::getItem(int index) {
    return items[index];
}

int main()
{
    int a = 12, b = 20, c;
    double d = 1.2, e = 6.3, f;

    string x = "asd", y ="alma", z;

    c = GetMax(a, b);
    f = GetMax(d, e);
    z = GetMax(x, y);

    cout << c << endl
         << f << endl
         << endl;

    sequence<int, 10> intSeq;
    sequence<double, 10> doubleSeq;

    intSeq.setItem(10, 2);
    doubleSeq.setItem(1.12, 2);

    cout << intSeq.getItem(2) << endl
         << doubleSeq.getItem(2) << endl;

    return 0;
}