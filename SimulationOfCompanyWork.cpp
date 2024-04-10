#include <iostream>
#include <vector>

class Worker
{
public:	
	std::string name = "unknow";
	bool isBusy = false;
	int employs = 0;

	void setEmploys(int& inEmploys)
	{
		employs = inEmploys;
	}	

	std::string getName()
	{
		return name;
	}

	int getEmploys()
	{
		return employs;
	}
};

class Manager : public Worker
{
private:	
	Worker** deportments = nullptr;	
	
public:

	Manager(int& inNumberCommands)
	{						
		deportments = new Worker*[inNumberCommands];

		for (int i = 0; i < inNumberCommands; ++i)
		{
			if (i == 0)
			{
				employs = 1;				
			}
			else
			{
				std::cout << "Enter the number of employees in the department " << i << " : ";
				std::cin >> employs;
			}
			deportments[i] = new Worker[employs];
			deportments[i]->setEmploys(employs);									
		}

		for (int i = 0; i < inNumberCommands; ++i)
		{			
			for (int j = 0; j < deportments[i]->getEmploys(); ++j)
			{
				if (i == 0)
				{
					std::cout << "Enter the name of the head of the company: ";
					//std::cin >> deportments[i][j].name;
					deportments[i][j].name = "Manager of Company";
					
				}
				else if (i > 0 && j == 0)
				{
					std::cout << "Enter the name of the department manager: ";
					//std::cin >> deportments[i][j].name;
					deportments[i][j].name = "Manager of department";
				}
				else
				{
					std::cout << "Enter employee name: ";
					//std::cin >> deportments[i][j].name;
					deportments[i][j].name = 'a' + j;
					deportments[i][j].isBusy;					
				}				
			}
		}

		for (int i = 0; i < inNumberCommands; ++i)
		{			
			for (int j = 0; j < deportments[i]->getEmploys(); ++j)
			{
				std::cout << deportments[i][j].getName() << std::endl;				
			}
		}		
	}

	

	//Worker getIndex(int index)
	//{
	//	return deportment[index];
	//}

};

int main()
{
	int numberCommands;

	numberCommands = 1;
	++numberCommands;

	Manager* personal = new Manager(numberCommands);


	






	/*for (int i = 0; i < numberCommands; ++i)
	{
		for (int j = 0; j < personal[i].getEmploys(); ++j)
		{
			std::cout << personal[i].getIndex(j).getName() << std::endl;
		}
	}*/



	std::cout << std::endl;




	delete personal;

	/* int a = rand();
	std::cout << a << std::endl;

	srand(time(NULL));
	a = rand() % 10 + 5;
	std::cout << a << std::endl;*/









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