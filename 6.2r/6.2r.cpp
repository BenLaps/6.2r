#include <iostream>

using namespace std;
struct Elem
{
    Elem* link;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int info) {
    Elem* tmp = new Elem;
    tmp->info = info;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void print(const Elem* first)
{
    if (first == nullptr)
        cout << endl;
    else
    {
        cout << first->info << " ";
        print(first->link);
    }
}

int count(const Elem* L)
{
    if (L != nullptr)
        return 1 + count(L->link);
    else
        return 0;
}

void remove2(Elem**& first1, int x)
{
    if (*first1 && (*first1)->info != x)
    {
        first1 = &(*first1)->link;
        remove2(first1, x);
    }
}

void remove1(Elem*& first, int x, int i)
{
    if (i < count(first))
    {
        Elem** first1 = &first;
        remove2(first1, x);
        if (!*first1)
        {
            return;
        }
        Elem* tmp = (*first1)->link;
        delete* first1;
        *first1 = tmp;
    }
    i++;
    remove1(first, x, i);
}

int main() {
    Elem* first = nullptr, * last = nullptr;
    enqueue(first, last, 1);
    enqueue(first, last, 22);
    enqueue(first, last, 23);
    enqueue(first, last, 47);
    enqueue(first, last, 3);
    enqueue(first, last, 8);
    enqueue(first, last, 11);
    enqueue(first, last, 1);

    print(first);
    int a;
    cout << "remove number "; cin >> a;
    remove1(first, a, 0);
    print(first);
    return 0;
}