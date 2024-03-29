// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* Emanuela Nimigean- gr 30226- QuickSort
Acest algoritm de sortare este unul rapid, dupa cum ii spune si numele, ce are la baza ideea de partitionare, fiind folosita strategia divide et impera.
In cazul general,  pentru a sorta n elemente, necesita in jur de nlogn operatii, iar eficienta in cazul mediu tinde spre cazul favorabil, nu spre cel defavorabil care are complexitatea O(n^2).
QuickSort nu este un algoritm stabil. In vederea imbunatatirii algoritmului, se foloseste randomizarea, aceasta fiind o metoda de sortare sensibila la ordinea datelor de intrare. Acest algoritm are dezavantajul de a fi recursiv.
Metoda alege un element din lista, numit pivot, pe care l-am ales random pentru cazul average, si rearanjeaza lista, prin interschimbari, mutand toate elementele mai mici decat pivotul inaintea lui si toate cele mai mari decat el, dupa acesta. Apoi, se apeleaza recursiv QuickSort pentru cele 2 partitii.
In cazul defavorabil, determinat de o lista deja ordonata crescator, numarul de operatii necesare este aproximativ n^2 deoarece pozitia pivotului ramane neschimbata(ultimul element), deci de fiecare data se imparte lista in doua liste, una vida si una cu n-1 elemente.
QuickSort est, in general, mai rapid decat HeapSort, exceptand cazul defavorabil, caz in care complexitatea lui este O(n^2), in timp ce complexitatea lui HS ramane O(nlogn), la fel ca in cazul favorabil. Viteza acestui algoritm vine din efectuarea a mai putine interschimbari fata de HS, neefectuand aproape deloc interschimbari care nu sunt necesare. In cazul  mediu, ambele metode au eficienta O(nlogn), QS tinde in acest caz catre cazul favorabil, nu catre cel defavorabil.
*/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int op = 0;

void swap(int *x, int *y)
{
	int z;
	z = *x;
	*x = *y;
	*y = z;
}

int partition(int a[], int l, int r)
{
	int pivot = rand() % (r - l) + l;
	swap(&a[r], &a[pivot]); op += 3;
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			op++;
			i++;
			swap(&a[j], &a[i]); op += 3;
		}
	}
	swap(&a[r], &a[i + 1]); op += 3;
	return i + 1;
}

int partitionWorst(int a[], int l, int r)
{
	//pivotul se alege ultimul element, a[r]
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			op++;
			i++;
			swap(&a[j], &a[i]); op += 3;
		}
	}
	swap(&a[r], &a[i + 1]); op += 3;
	return i + 1;
}


void QuickSort(int a[], int l, int r)
{
	if (l < r)
	{
		int q = partition(a, l, r);
		QuickSort(a, l, q - 1);
		QuickSort(a, q + 1, r);
	}
}


void QuickSortWorst(int a[], int l, int r)
{
	if (l < r)
	{
		int q = partitionWorst(a, l, r);
		QuickSortWorst(a, l, q - 1);
		QuickSortWorst(a, q + 1, r);
	}
}

int QuickSelect(int a[], int l, int r, int i)
{
	if (l == r)
		return a[l];
	int q = partition(a, l, r);
	int aux = q - l + 1;
	if (aux == i)
		return a[q];
	else
		if (aux > i)
			return QuickSelect(a, l, q - 1, i);
		else
			return QuickSelect(a, q + 1, r, i - aux);
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void generateRandom(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}
}

void generateWorst(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}


int main()
{
	/*//rulare
	int a[] = { 2,1,6,7,4,9,4 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a,0,n-1);
	printArr(a, n);
	printf("\n %d", op);
	printf("\n %d ", QuickSelect(a, 0, n - 1, 1));
	*/

	int a[10000], sum = 0;
	
	/*for (int i = 100; i <= 10000; i += 500)
	{
		op = 0; sum = 0;
		for (int j = 0; j < 5; j++)
		{
			generateRandom(a, i);
			QuickSort(a, 0, i - 1);
			printf("\n %d ", op);
			sum += op;
		}
		printf(" %d ", sum/5);
	}*/

	/*for (int i = 100; i <= 10000; i += 500)
	{
		op = 0;
		generateWorst(a, i);
		QuickSortWorst(a, 0, i - 1);
		printf("\n %d ", op);
	}*/

	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
