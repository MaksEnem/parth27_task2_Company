#include <iostream>
#include <vector>
#include <ctime>

enum Tusks
{
    A, B, C
};

class Employees
{
    int commands = 0;
    int workers = 0;
    std::string name = "a";
    std::vector<std::vector<std::string>> employees;

public:
    Employees()
    {
        std::cout << "Enter the number of commands: ";
        std::cin >> commands;
        ++commands;       

        for (int i = 0; i < commands; ++i)
        {          
            std::vector<std::string> rowEmployees;

            if (i == 0)
            {
                workers = 1;
            }
            else 
            {
                std::cout << "Enter the number of employees in " << i << " department: ";
                std::cin >> workers;
            }
            for (int j = 0; j < workers; ++j)
            {
                //std::cout << "Enter name: ";
                //std::cin >> name;
                name = 'a' + i + j;
                rowEmployees.push_back(name);
            }
            employees.push_back(rowEmployees);            
        }       
    }

    void printNames()
    {
        for (int i = 0; i < commands; ++i)
        {
            for (int j = 0; j < employees[i].size(); ++j)
            {
                std::cout << employees[i][j] << std::endl;
            }
        }
    }    
};

class Managers : public Employees
{
private:
    int chapterIndication = 0;
    int managementIndication = 0;

public:
    void setInstructionsFromTheHeadCompany()
    {
        std::cout << "Enter instructions: ";
        std::cin >> chapterIndication;
        srand(chapterIndication);
        chapterIndication = rand();        
    }

    int get()
    {
        return chapterIndication;
    }

};




int main()
{
    Managers* asd = new Managers();
    //asd->printNames();
    asd->setInstructionsFromTheHeadCompany();


   /* int a = rand();

    std::cout << a << std::endl;

    

    srand(time(NULL));

    a = rand() % 10 + 5;

    std::cout << a << std::endl;*/

    return 0;
}