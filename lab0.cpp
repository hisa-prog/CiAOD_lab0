#include <iostream>
#include <fstream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int first_number = 0, number = 0;
	//Переменная first_number предназначена для числа, которое будет считываться первым и являться числом, на которое будем умножать числа из 2-й строки.
	//Переменная number предназначена для чтения чисел со второй строки.

	std::cout << "\nИндивидуальное задание №7";
	std::cout << "\nВ первой строке файла содержится 1 целое число. Во второй строке задано 15 целых чисел.";
	std::cout << "\nПрограмма должна считать файл и выполнить операцию умножения числа из первой строки с каждым числом из второй строки.";
	std::cout << "\nВыходной файл должен содержать 15 чисел – результаты выполнения операций умножения.";
	std::cout << "\nВходной файл :";
	std::cout << "\n2";
	std::cout << "\n1 2 3 4 ... 15";
	std::cout << "\nВыходной файл :";
	std::cout << "\n2 4 6 8 10 12 14 16 18 20 22 24 26 28 30\n";


	std::cout << "\n\nОткрываем файл для чтения!";
	std::ifstream FileIn("Enter.txt"); //открыли файл для чтения.

	if (FileIn.is_open())
		std::cout << "\nФайл успешно открыт!";
	else {
		std::cout << "\nФайл не был открыт!";
		return 1;
	}
	
	FileIn >> first_number; //считали 2-ку и поместили в переменную.

	std::cout << "\n\nОткрываем файл для записи!";
	std::ofstream FileOut("Out.txt", std::ios_base::trunc);//открыли файл для записи

	if (FileOut.is_open())
		std::cout << "\nФайл успешно открыт!";
	else {
		std::cout << "\nФайл не был открыт!";
		return 1;
	}

	std::cout << "\n\nЧисла со второй строки, которые нужно умножить: ";
	while (!FileIn.eof())
	{
		FileIn >> number;
		std::cout << number << " ";
		FileOut << number * first_number << " ";
	}
	
	std::cout << "\n\nЗакрываем файл, который был для чтения!";
	FileIn.close(); //  закрываем файл
	
	std::cout << "\n\nЗакрываем файл, который был для записи!\n";
	FileOut.close();

	system("pause");

	return 0;
}
