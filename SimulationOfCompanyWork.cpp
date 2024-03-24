#include <iostream>
#include <cassert>

class Employees
{
    int commands = 0;
    int workers = 0;
    std::string name;
    std::string** employees = nullptr;
public:
    Employees()
    {
        std::cout << "Enter the number of commands: ";
        std::cin >> commands;
        ++commands;

        employees = new std::string*[commands];
//
        for (int i = 0; i < commands; ++i)
        {
            if (i == 0)
            {
                workers = 1;
            }
            else
            {
                std::cout << "Enter the number of employees in " << i << " department: ";
                std::cin >> workers;
               
            }   
            employees[i] = new std::string[workers];
        }

        for (int i = 0; i < commands; ++i)
        {
            for (int j = 0; j < workers; ++j)
            {
              
               employees[i][j] = 'a' + i + j;
            }
        }

        for (int i = 0; i < commands; ++i)
        {
            for (int j = 0; j < workers; ++j)
            {

               std::cout <<  employees[i][j] << std::endl;
            }
        }

    }
    
};

int main()
{
    Employees* asd = new Employees();



    return 0;
}