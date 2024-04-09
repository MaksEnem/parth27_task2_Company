#include <iostream>
#include <vector>

class Worker
{
public:
	//int employs = 0;
	std::string name = "unknow";
	bool isBusy = false;


	void setName()
	{
		std::cout << "Enter name: ";
		std::cin >> name;
		//name = '1';
	}

	void setIsBusy()
	{
		isBusy = false;
	}

	std::string getName()
	{
		return name;
	}

};

class Manager : public Worker
{
private:
	//std::vector<Worker> deportment;
	Worker* deportment = nullptr;
	//Worker* personal = nullptr;
	int employs = 0;
public:

	Manager()
	{
		std::cout << "Enter the number of employees in the team: ";
		std::cin >> employs;
		deportment = new Worker[employs];

		for (int i = 0; i < employs; ++i)
		{
			deportment[i].setName();
			deportment[i].setIsBusy();
		}
	}



	int getEmploys()
	{
		return employs;
	}

	Worker getIndex(int index)
	{
		return deportment[index];
	}

};

int main()
{
	int numberCommands;
	//std::cout << "Enter number of command: ";
	//std::cin >> command;

	numberCommands = 1;
	++numberCommands;


	Manager* personal = new Manager[numberCommands];


	for (int i = 0; i < numberCommands; ++i)
	{
		for (int j = 0; j < personal[i].getEmploys(); ++j)
		{
			std::cout << personal[i].getIndex(j).getName() << std::endl;
		}
	}



	std::cout << std::endl;




	delete[] personal;
	/*std::vector<int> vec;
	for (int i = 0; i < command; ++i)
	{
		vec.push_back(1);
	}*/


	/*std::vector<Manager> deportment(command);

	for (int i = 0; i < command; ++i)
	{
		std::cout << deportment[i].getName() << std::endl;
	}*/


}