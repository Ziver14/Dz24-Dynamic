#include<iostream>
#include<ctime>
#include<cstdlib>

template<typename T>
void fill_arr(T arr[], const int length, int right, int left) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}

void resize_arr(int*& arr, const int begin_length, const int end_length) {
	if (begin_length == end_length || end_length <= 0)
		return;
	if (end_length > begin_length) {
		int* tmp = new int[end_length] {};
		for (int i = 0; i < begin_length; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
	else {
		int* tmp = new int[end_length];
		for (int i = 0; i < end_length; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
		
	
}




int main() {
	setlocale(LC_ALL, "ru");


	//Задача 1. Соединение динамических массивов
	std::cout << "Введите длинны массивов -> ";
	int size1, size2;
	std::cin >> size1 >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];


	std::cout << "Первый массив -> \n";
	fill_arr(arr1, size1, 10, 50);
	print_arr(arr1, size1);

	std::cout << "Второй массив ->\n";
	fill_arr(arr2, size2, 10, 50);
	print_arr(arr2, size2);

	int* arr3 = new int[size1 + size2];
	for (int i = 0; i < size1; i++)
		arr3[i] = arr1[i];
	for (int i = 0; i < size1 + size2; i++)
		arr3[i + size1] = arr2[i];
	std::cout << "Итоговый массив -> \n";
	print_arr(arr3, size1 + size2);
	delete[] arr1;
	delete[] arr2;
	std::cout << "\n\n";

	//Задача 2. Изменение длины массива.
	int n, m;
	std::cout << "Введите начальную длинну массива-> ";
	std::cin >> n;
	int* arr4 = new int[n];
	std::cout << "Изначальный массив ->\n";
	fill_arr(arr4, n, 10, 50);
	print_arr(arr4, n);
	std::cout << "Введите новую длину массива-> ";
	std::cin >> m;
	resize_arr(arr4, n, m);
	if (m < 0)
		std::cout << "Ошибка ввода!!!";
	else {
		std::cout << "Измененный массив -> \n";
		print_arr(arr4, m);
	}

	

	return 0;
}