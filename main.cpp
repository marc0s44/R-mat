#include <iostream>
#include <cmath>
#include <fstream>
void PrintArray(int** tab, int n);
void rmat();

using namespace std;
fstream file;
int main()
{
	file.open("RMAT.txt", fstream::out);
	rmat();
	file.close();
	system("pause");
	return 0;
}
void rmat()
{
	cout << "Program which generates graphs (RMAT)" << endl;
	int n;
	cout << "1. Directed graph" << endl;
	cout << "2. Undirected graph" << endl;
	int choice;
	cout << "Your choice: ";
	cin >> choice;
	cout << "\nGive n for square matrix 2^n: ";
	cin >> n;
	float p;
	cout << "Give density of the graph (0.0 - 1.0): ";
	cin >> p;
	int p1, p2, p3, p4;
	cout << "Probability for the 1 quarter: ";
	cin >> p1;
	cout << "Probability for the 2 quarter: ";
	cin >> p2;
	cout << "Probability for the 3 quarter: ";
	cin >> p3;
	cout << "Probability for the 4 quarter: ";
	cin >> p4;
	unsigned short x = 0;
	unsigned short y = 0;
	unsigned short width = n;
	unsigned short height = n;
	unsigned short random_number = 0;
	unsigned short previous = 0;
	int size;
	size = pow(2, n);
	int** tab = new int* [size];
	for (int i = 0; i < size; ++i)
		tab[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			tab[i][j] = 0;
	int condition;
	if (choice == 1)
		condition = size * (size - 1) * p;
	else
		condition = ((size * (size - 1)) / 2) * p;
	while (condition > previous)
	{
		width = size;
		height = size;
		x = 0;
		y = 0;
		while (width > 1)
		{
			random_number = (rand() % 100) + 1;
			if (random_number <= p1)
			{
				width /= 2;
				height /= 2;
			}
			else if (random_number > p1 && random_number <= (p1 + p2))
			{
				y += height / 2;
				width /= 2;
				height /= 2;
			}
			else if (random_number > (p1 + p2) && random_number <= (p1 + p2 + p3))
			{
				x += width / 2;
				width /= 2;
				height /= 2;
			}
			else
			{
				x += width / 2;
				y += height / 2;
				width /= 2;
				height /= 2;
			}
		}
		if (tab[x][y] != 1)
		{
			tab[x][y] = 1;
			if (choice == 2)
				tab[y][x] = 1;
			previous += 1;
		}
	}
	PrintArray(tab, size);

	for (int i = 0; i < size; ++i) {
		delete[] tab[i];
	}
	delete[] tab;


}
void PrintArray(int** tab, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tab[i][j];
			file << tab[i][j];
		}
		cout << endl;
		file << endl;
	}

}
