﻿#include <iostream>
#include <fstream>

using namespace std;
class op {
    struct down {
        int arr;
        int k;
        down* z;
        down* next;
        down() {
            next = NULL;
            z = NULL;
            k = 0;
        }

    };
    down* head;

public:
    op() :head(NULL) {}
    void open(int a)
    {
        bool f = 0;
        down* tmp = new down;
        
        if (head != NULL)
        {
            down* p = head;
            do {
                if (p->arr == a)
                {
                    tmp->z = p;
                    if (p->z == NULL)
                        tmp->z->k++;
                }
                p = p->next;
            } while (p != NULL);
        }
        if (f == 0)
        {
            tmp->arr = a;
        }
        tmp->next = head;
        head = tmp;

    }
    void lzw()
    {
        if (head != NULL)
        {
            down* tmp = head;
            do {
                if (tmp->z != NULL)
                    tmp->arr = NULL;
                tmp = tmp->next;
            } while (tmp != NULL);
        }
        down* p = head;
    
    }
    void lzb() 
    {
        if (head != NULL)
        {
            down* tmp = head;
            do {
                if (tmp->z != NULL)
                    tmp->arr = tmp->z->arr;
                tmp = tmp->next;
            } while (tmp != NULL);
        }
    }
    void dele(int a,bool f)
    {
        if (head != NULL)
        {
            
            if (a == head->arr)
            {
                down* one = head->next;
                if (head->z != NULL)
                    head->z->k--;
                delete head;
                head = one;
                return;
            }
            down* one = head;
            down* two = head->next;
            while (two != NULL)
            {
                if (a == two->arr)
                {
                    if (two->z != NULL)
                        two->z->k--;
                    one->next = two->next;
                    two = two->next;
                    
                    break;
                }
                two = two->next;
                one = one->next;
            }
        }
        if (f == 1) {
            down* tmp = head;
            do {
                if (tmp->z != NULL)
                    if (tmp->z->arr = a)
                        tmp->z = NULL;
                tmp = tmp->next;
            } while (tmp != NULL);
        }
    }
    void output()
    {
        if (head != NULL)
        {
            down* p = head;
            do {
                if(p->arr!=NULL)
                    if(p->k==0)
                        cout << p->arr <<endl;
                    else
                        cout << p->arr <<"-повторов: "<<p->k << endl;
                p = p->next;
            } while (p != NULL);
            cout << endl;
        }
        else
            cout << "Небыло записанно" << endl;
    }
};
int main()
{
    
    setlocale(LC_ALL, "Rus");
    op t1;
    bool f=0;
    int a = 0;
    t1.open(1);
    t1.open(2);
    t1.open(3);
    t1.open(2);
    t1.open(2);
    t1.open(1);
    t1.open(2);
    while (a != 5)
    {
        cout << "1.Запись" << endl;
        cout << "2.Вывод без сжатия " << endl;
        cout << "3.Вывод с жатием." << endl;
        cout << "4.Удалить." << endl;
        cout << "5.Выход." << endl;
        cout << "Ваш выбор : "; cin >> a;
        system("cls");
        switch (a)
        {
        case 1: {
            int b = 0;
            cout << "Новое число списка  = "; cin >> b;
            t1.open(b);
            f = 0;
            break;
        }
        case 2: {    
            t1.lzb();
            f = 0;
            t1.output();
            break;
        }
        case 3: {
            t1.lzw();
            f = 1;
            t1.output();
            break;
        }
        case 4: {
            t1.output();
            int b = 0;
            cout << "Что удалить  = "; cin >> b;
            t1.dele(b,f);
            t1.output();
            break;
        }
        }
    }
    return 0;
}

