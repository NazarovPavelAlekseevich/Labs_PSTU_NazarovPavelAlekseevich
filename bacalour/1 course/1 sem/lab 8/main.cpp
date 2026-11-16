#include <stdio.h>
#include <iostream>
using namespace std;

struct stadium{ //Форма для стадиона
    char name[30];
    int year;
    int number_of_grounds;
    char sports[100];
};

int main(){
    FILE* f; FILE* temp; // создание указателя на файл
    f = fopen("main.txt", "wb"); //открытие файлов
    temp = fopen("temp.txt", "wb");
    if(f == NULL || temp == NULL) return 1; // проверка на ошибки
    setlocale(LC_ALL,".65001");

    printf("Сколько стадионов: "); int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){ // ввод для 1 стадиона в цикле + заносим в файл информацию
        stadium s;
        printf("%s%d","\nВведите информацию о стадионе номер ", i+1);
        printf("\nНазвание: "); scanf("%s", s.name);
        printf("Год постройки: "); scanf("%d", &s.year);
        printf("Количество площадок: "); scanf("%d", &s.number_of_grounds);
        printf("Виды спорта: "); scanf(" %99[^\n]", s.sports);
        fwrite(&s, sizeof(stadium), 1, f);
    }
    fclose(f); //закрываем файл
    stadium s; // создаём шаблонную переменную

    int year; // граница для сортировки стадионов
    printf("\nУдалить стадионы, построенные раньше какого года: "); scanf("%d", &year);

    f = fopen("main.txt", "rb"); // открываем для чтения
    int deleted = 0; // количество удалённых стадионов
    while (fread(&s, sizeof(stadium), 1, f) == 1){
        if (s.year < year){++deleted; continue;}
        fwrite(&s, sizeof(stadium), 1, temp); // перезапись
    }
    fclose(temp); // закрываем файлы
    fclose(f);

    if (deleted > 0){remove("main.txt"); rename("temp.txt", "main.txt");}
    else remove("temp.txt"); // меняем файлы
    printf("Удалено записей: %d\n", deleted);

    f = fopen("main.txt", "rb");
    int i = 1;
    printf("\n\tИнформация после редактирования:\n");
    while (fread(&s, sizeof(stadium), 1, f) == 1) // выводим информацию
        printf("%s %d %s %s %s %d %s %d %s %s %s", "\nСтадион номер", i++, "\nНазвание:", s.name, \
            "\nГод постройки:", s.year, "\nКоличество площадок:", s.number_of_grounds,\
            "\nВиды спорта:", s.sports, "\n");
    fclose(f); // закрваем файлы

    remove("main.txt"); // удаляем файл
    return 0;
}