#include <iostream>
#include <vector>
enum Task
{
	A, B, C
};

class Worker
{
public:	
	std::string name = "unknow";
	bool isBusy = false;
	int employs = 0;
	int freeWorkers = 0;
	
	void setName(std::string& inName)
	{
		name = inName;
	}

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

	int getFreeWorkers()
	{
		return freeWorkers;
	}

	void setInitialBusyWorkers()
	{
		isBusy = false;
	}

	void setInitialFreeWorkers()
	{
		freeWorkers = 0;
	}

	void setFreeWorkers()
	{
		++freeWorkers;
	}

	void setBusyWorkers()
	{
		isBusy = true;
	}

	bool getBusyWorkers()
	{
		return isBusy;
	}
};

class Manager : public Worker
{
private:	
	Worker** deportments = nullptr;	
	int tasks = 0;
	int instructionsGeneralManager = 0;
	int departmentManagerInstructions = 0;
	
	int* taskManger = nullptr;
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
					deportments[i][j].setInitialBusyWorkers();					
				}				
			}
		}

		/*for (int i = 0; i < inNumberCommands; ++i)
		{
			for (int j = 0; j < deportments[i]->getEmploys(); ++j)
			{
				std::cout << deportments[i][j].getName() << std::endl;
			}
		}*/
		taskManger = new int[inNumberCommands];
	}

	void setStatementManager(int & index)
	{
		if (index == 0)
		{
			std::cout << "Enter tasks: ";
			std::cin >> taskManger[index];			
		}
		else
		{
			taskManger[index] = taskManger[0] + index;
			srand(taskManger[index]);
			deportments[index]->setInitialFreeWorkers();

			for (int i = 1; i < deportments[index]->getEmploys(); ++i)
			{
				if (deportments[index][i].isBusy == false)
				{
					deportments[index]->setFreeWorkers();					
				}
			}

			if (deportments[index]->getFreeWorkers() > 0)
			{				
				taskManger[index] = rand() % deportments[index]->getFreeWorkers() + 1;

				for (int i = 1; i < deportments[index]->getEmploys(); ++i)
				{					
					if (deportments[index][i].isBusy == false)
					{
						deportments[index][i].isBusy == true;
						--taskManger[index];						
					}
					if (taskManger[index] == 0)
					{
						break;
					}
				}
			}			
		}
	}

	

	

	/*int getStatementProblemGeneralManager()
	{
		return instructionsGeneralManager;
	}

	int getStatementProblemDepartmentManager(int& index)
	{
		return departmentManagerInstructions;
	}*/

	Worker* getIndex(int& index)
	{
		return deportments[index];
	}


	Worker getTestIndex(int& index1, int& index2)
	{
		return deportments[index1][index2];
	}
};

int main()
{
	int numberCommands;

	numberCommands = 2;
	++numberCommands;

	Manager* company = new Manager(numberCommands);

	std::cout << std::endl;

	for (int i = 0; i < numberCommands; ++i)
	{
		
		std::cout << company->getIndex(i)->getName() << std::endl;
		//company->setDepartmentManagerInstructions(i);
		
	}
	std::cout << std::endl;




	for (int i = 0; i < numberCommands; ++i)
	{
		//std::cout << company->getIndex(i) << std::endl;
		company->setStatementManager(i);
	}
	






	delete company;

	return 0;
}