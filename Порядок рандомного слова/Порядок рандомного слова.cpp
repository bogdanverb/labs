#include<iostream>
#include<random>
#include <windows.h>

struct Struct
{
	std::string word;
	int* index;
};

int Random(int max)  
{
	std::random_device rd; 
	std::mt19937 random(rd()); 
	std::uniform_int_distribution<> distrib(0, max); 

	return distrib(random);
}

void Swaping(Struct& t)
{

	int random1 = Random(t.word.size() - 1);
	int random2 = Random(t.word.size() - 1);


	while (random1 == random2)
	{
		random2 = Random(t.word.size() - 1);
	}

	std::swap(t.word[random1], t.word[random2]);
	std::swap(t.index[random1], t.index[random2]);

}

bool index_comparison(Struct& t, Struct& sor)
{
	for (int i = 0; i < t.word.size(); i++)
	{
		if (t.index[i] == sor.index[i])
			continue;

		return false;
	}
	return true;
}

int main()
{

	setlocale(0, "");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Struct user_word;
	Struct control_word;

	std::cout << "Введите слово: ";
	std::cin >> user_word.word;

	user_word.index = new int[user_word.word.size()];
	control_word.index = new int[user_word.word.size()];
	int count = 1;



	for (int i = 0; i < user_word.word.size(); i++)
	{
		user_word.index[i] = i;
		control_word.index[i] = i;
	}

	control_word.word = user_word.word;

	while (1)
	{


		Swaping(user_word);

		std::cout << "[" << count++ << "] ";
		for (int i = 0; i < user_word.word.size(); i++)
		{
			std::cout << user_word.index[i];
		}
		std::cout << " " << user_word.word << std::endl;

		bool prov = index_comparison(user_word, control_word);

		if (control_word.word == user_word.word && prov)
			break;


	}

	delete[] user_word.index;
	delete[] control_word.index;

	return 0;
}