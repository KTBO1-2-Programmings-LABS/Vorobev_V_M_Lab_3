#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <stdbool.h>
#include <stdlib.h>

struct film
{
    char name[99], producer_name[99], producer_surname[99], producer_patronymic[99], country[99];
    long cost, income, year;
};

void print_comands()
{
    printf("�������� �������:\n");
    printf("1 = ���������� ������ ������\n");
    printf("2 = ����� ������ �� ���������� ��������\n");
    printf("3 = ����� ������ �������\n");
    printf("4 = ���������� ������ �� ����\n");
    printf("0 = ��������� ���������\n");
}

void print_find_sort()
{
    printf("1 = �������� ������\n");
    printf("2 = ��� ����������\n");
    printf("3 = ������� ����������\n");
    printf("4 = �������� ����������\n");
    printf("5 = ������, �������� ����� �����\n");
    printf("6 = ���, ����� ����� �����\n");
    printf("7 = ������ ������\n");
    printf("8 = ����� ������\n");
}

int main()
{
    FILE* fp1;
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    struct film new_film, tmp;
    struct film films[999];
    int antwort = -1, amount = 0, antwort_1 = -1, antwort_1_int;
    char data1[999], antwort_1_str[999], new_year[5], new_cost[999], new_income[999];
    bool flag = false;
    while (antwort != 0)
    {
        print_comands();
        scanf("%d", &antwort);
        if (antwort == 1)
        {
            if ((fp1 = fopen("./data_file.txt", "a")) == NULL)
            {
                printf("���� �� ������!");
            }
            else
            {
                printf("������� �������� ������ ");
                scanf("%s", &new_film.name);
                printf("������� ��� ���������� ");
                scanf("%s", &new_film.producer_name);
                printf("������� ������� ���������� ");
                scanf("%s", &new_film.producer_surname);
                printf("������� �������� ���������� ");
                scanf("%s", &new_film.producer_patronymic);
                printf("������� ������, � ������� �������� ����� ");
                scanf("%s", &new_film.country);
                printf("������� ���, ����� ��� ������� ����� ");
                scanf("%ld", &new_film.year);
                printf("������� ������ ������ ");
                scanf("%ld", &new_film.cost);
                printf("������� �������� ����� ������ ");
                scanf("%ld", &new_film.income);
                fprintf(fp1, "%s\t%s\t%s\t%s\t%s\t%ld\t%ld\t%ld\n", new_film.name, new_film.producer_name, new_film.producer_surname, new_film.producer_patronymic, new_film.country, new_film.year, new_film.cost, new_film.income);
                amount++;
                fclose(fp1);
            }
        }
        if (antwort == 3)
        {
            if ((fp1 = fopen("./data_file.txt", "r")) == NULL)
            {
                printf("���� �� ������!");
            }
            else
            {
                printf("--------------\n");
                for (int i = 0; i < amount; i++)
                {
                    fgets(data1, 999, fp1);
                    strcpy(new_film.name, strtok(data1, "\t"));
                    strcpy(new_film.producer_name, strtok(NULL, "\t"));
                    strcpy(new_film.producer_surname, strtok(NULL, "\t"));
                    strcpy(new_film.producer_patronymic, strtok(NULL, "\t"));
                    strcpy(new_film.country, strtok(NULL, "\t"));
                    strcpy(new_year, strtok(NULL, "\t"));
                    new_film.year = strtol(new_year, NULL, 10);
                    strcpy(new_cost, strtok(NULL, "\t"));
                    new_film.cost = strtol(new_cost, NULL, 10);
                    strcpy(new_income, strtok(NULL, "\n"));
                    new_film.income = strtol(new_income, NULL, 10);
                    printf("�����: %s\n", new_film.name);
                    printf("���������: %s %s %s\n", new_film.producer_name, new_film.producer_surname, new_film.producer_patronymic);
                    printf("������: %s\n", new_film.country);
                    printf("���: %ld\n", new_film.year);
                    printf("������: %ld\n", new_film.cost);
                    printf("�����: %ld\n", new_film.income);
                    printf("--------------\n");
                }
                fclose(fp1);
            }
        }
        if (antwort == 2)
        {
            printf("�� ������ �������� ������ ����� �����?\n");
            print_find_sort();
            scanf("%d", &antwort_1);
            printf("������� ��� �������� ");
            if (antwort_1 <= 5)
            {
                scanf("%s", &antwort_1_str);
            }
            else
            {
                scanf("%d", &antwort_1_int);
            }
            if ((fp1 = fopen("./data_file.txt", "r")) == NULL)
            {
                printf("���� �� ������!");
            }
            else
            {
                for (int i = 0; i < amount; i++)
                {
                    fgets(data1, 999, fp1);
                    strcpy(new_film.name, strtok(data1, "\t"));
                    strcpy(new_film.producer_name, strtok(NULL, "\t"));
                    strcpy(new_film.producer_surname, strtok(NULL, "\t"));
                    strcpy(new_film.producer_patronymic, strtok(NULL, "\t"));
                    strcpy(new_film.country, strtok(NULL, "\t"));
                    strcpy(new_year, strtok(NULL, "\t"));
                    new_film.year = strtol(new_year, NULL, 10);
                    strcpy(new_cost, strtok(NULL, "\t"));
                    new_film.cost = strtol(new_cost, NULL, 10);
                    strcpy(new_income, strtok(NULL, "\n"));
                    new_film.income = strtol(new_income, NULL, 10);
                    flag = false;
                    if (antwort_1 == 1 && (strcmp(new_film.name, antwort_1_str) == 0))
                    {
                        flag = true;
                    }
                    if (antwort_1 == 2 && (strcmp(new_film.producer_name, antwort_1_str) == 0))
                    {
                        flag = true;
                    }
                    if (antwort_1 == 3 && (strcmp(new_film.producer_surname, antwort_1_str) == 0))
                    {
                        flag = true;
                    }
                    if (antwort_1 == 4 && (strcmp(new_film.producer_patronymic, antwort_1_str) == 0))
                    {
                        flag = true;
                    }
                    if (antwort_1 == 5 && (strcmp(new_film.country, antwort_1_str) == 0))
                    {
                        flag = true;
                    }
                    if (antwort_1 == 6 && new_film.year == antwort_1_int)
                    {
                        flag = true;
                    }
                    if (antwort_1 == 7 && new_film.cost == antwort_1_int)
                    {
                        flag = true;
                    }
                    if (antwort_1 == 8 && new_film.income == antwort_1_int)
                    {
                        flag = true;
                    }
                    if (flag)
                    {
                        printf("����� ������!\n");
                        printf("�����: %s\n", new_film.name);
                        printf("���������: %s %s %s\n", new_film.producer_name, new_film.producer_surname, new_film.producer_patronymic);
                        printf("������: %s\n", new_film.country);
                        printf("���: %ld\n", new_film.year);
                        printf("������: %ld\n", new_film.cost);
                        printf("�����: %ld\n", new_film.income);
                        break;
                    }
                }
                if (!flag)
                {
                    printf("����� �� ������!\n");
                }
                fclose(fp1);
            }
        }
        if (antwort == 4)
        {
            if ((fp1 = fopen("./data_file.txt", "r")) == NULL)
            {
                printf("���� �� ������!");
            }
            else
            {
                for (int i = 0; i < amount; i++)
                {
                    fgets(data1, 999, fp1);
                    strcpy(new_film.name, strtok(data1, "\t"));
                    strcpy(new_film.producer_name, strtok(NULL, "\t"));
                    strcpy(new_film.producer_surname, strtok(NULL, "\t"));
                    strcpy(new_film.producer_patronymic, strtok(NULL, "\t"));
                    strcpy(new_film.country, strtok(NULL, "\t"));
                    strcpy(new_year, strtok(NULL, "\t"));
                    new_film.year = strtol(new_year, NULL, 10);
                    strcpy(new_cost, strtok(NULL, "\t"));
                    new_film.cost = strtol(new_cost, NULL, 10);
                    strcpy(new_income, strtok(NULL, "\n"));
                    new_film.income = strtol(new_income, NULL, 10);
                    films[i] = new_film;
                }
                for (int i = amount - 1; i >= 0; i--)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (films[j].year > films[j + 1].year)
                        {
                            tmp = films[j];
                            films[j] = films[j + 1];
                            films[j + 1] = tmp;
                        }
                    }
                }
                printf("��������������!\n");
                printf("--------------\n");
                for (int i = 0; i < amount; i++)
                {
                    printf("�����: %s\n", films[i].name);
                    printf("���������: %s %s %s\n", films[i].producer_name, films[i].producer_surname, films[i].producer_patronymic);
                    printf("������: %s\n", films[i].country);
                    printf("���: %ld\n", films[i].year);
                    printf("������: %ld\n", films[i].cost);
                    printf("�����: %ld\n", films[i].income);
                    printf("--------------\n");
                }
                fclose(fp1);
            }
        }   
    }
    return 0;
}