#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define fflush while (getchar() != '\n')

typedef struct{
    char marka[30]; //Марка
    char model[30]; //Модель
    float engine; //Мощность двигателя
    int power; //Кол-во л.с.
    char transmission[9]; //Коробка передач
    char color[20]; //Цвет машины
    int year; //Год автомобиля
    int price; //Цена
}car;

void Init(car* q) {
    q->marka[0] = 0;
    q->model[0] = 0;
    q->engine = 0;
    q->power = 0;
    q->transmission[0] = 0;
    q->color[0] = 0;
    q->year = 0;
    q->price = 0;
}

void Read(car* q) {
    printf("Введите марку машины: ");
    gets_s(q->marka);
    printf("Введите модель машины: ");
    gets_s(q->model);
    printf("Введите мощность двигателя(объём двигателя): ");
    scanf_s("%f", &q->engine);
    fflush;
    printf("Введите кол-во л.с.: ");
    scanf_s("%d", &q->power);
    fflush;
    printf("Введите тип трансмиссии(коробка передач): ");
    gets_s(q->transmission);
    printf("Введите цвет автомобиля: ");
    gets_s(q->color);
    printf("Введите год автомобиля: ");
    scanf_s("%d", &q->year);
    fflush;
    printf("Введите цену за данный автомобиль: ");
    scanf_s("%d", &q->price);
    fflush;
    printf("\n");
}

void Display(car* q) {
    printf("%-15s %-15s %-5.1f %-4d %-10s %-15s %-6d %-16d\n", q->marka, q->model, q->engine, q->power, q->transmission, q->color, q->year, q->price);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("color 70");

    int k;
    do {
        puts("Сколько автомобилей вы собиретесь добавить?");
        scanf_s("%d", &k);
        fflush;
    } while (k < 1);
    printf("\n");
    car* q;
    q = (car*)calloc(k, sizeof(car));
    for (int i = 0; i < k; i++) {
        Init(q + i);
        Read(q + i);
    }
    system("cls");
    for (int i = 0; i < k; i++) {
        Display(q + i);
    }
}

