#include <iostream>

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

	void setInitialFreeWorkers()
	{
		freeWorkers = 0;
	}

	void setFreeWorkers()
	{
		++freeWorkers;
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
				}				
			}
		}
		taskManger = new int[inNumberCommands];
	}

	void printIsBusy(int & inNumberCommands)
	{
		for (int i = 0; i < inNumberCommands; ++i)
		{
			for (int j = 0; j < deportments[i]->getEmploys(); ++j)
			{
				if (deportments[i][j].isBusy == false)
				{
					std::cout << "false" << std::endl;
				}
				else
				{
					std::cout << "true" << std::endl;
				}
			}
		}
	}

	void printBusyWorkers(int& inNumberCommands)
	{
		for (int i = 0; i < inNumberCommands; ++i)
		{
			for (int j = 0; j < deportments[i]->getEmploys(); ++j)
			{
				if (j == 0)
				{
					deportments[i][j].isBusy = true;
				}
				
			}
		}
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
			std::cout << "deportments[index]->getFreeWorkers()" << deportments[index]->getFreeWorkers() << std::endl;
			if (deportments[index]->getFreeWorkers() > 0)
			{				
				taskManger[index] = rand() % deportments[index]->getFreeWorkers() + 1;

				for (int i = 1; i < deportments[index]->getEmploys(); ++i)
				{					
					if (deportments[index][i].isBusy == false)
					{
						deportments[index][i].isBusy = true;
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

	void setBusyManager(int& index)
	{
		for (int i = 1; i < deportments[index]->getEmploys(); ++i)
		{
			if (deportments[index]->getFreeWorkers() == 0)
			{
				deportments[index][0].isBusy = true;
			}
		}
	}

	bool getBusyGeneralManager(int& inNumberCommands)
	{
		for (int i = 1; i < inNumberCommands; ++i)
		{
			if (deportments[i][0].isBusy == false)
			{				
				//return deportments[0][0].getBusyWorkers();
				return deportments[0][0].isBusy;
			}
		}
		deportments[0][0].isBusy = true;
		//return deportments[0][0].getBusyWorkers();
		return deportments[0][0].isBusy;
	}

	bool getBusyManager(int& index)
	{
		if(index > 0) return deportments[index][0].isBusy;
	}
	
	/*Worker* getIndex(int& index)
	{
		return deportments[index];
	}


	Worker getTestIndex(int& index1, int& index2)
	{
		return deportments[index1][index2];
	}*/

};

int main()
{
	int numberCommands;

	numberCommands = 2;
	++numberCommands;

	Manager* company = new Manager(numberCommands);

	while (true)
	{
		for (int i = 0; i < numberCommands; ++i)
		{
			company->setStatementManager(i);
			company->setBusyManager(i);
		}

		if (company->getBusyGeneralManager(numberCommands))
		{
			std::cout << "Exit" << std::endl;
			delete company;
			return 0;
		}		
	}
}