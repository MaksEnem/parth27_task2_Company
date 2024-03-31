#include <iostream>
#include <vector>

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

       

        std::cout << "commands: " << commands << std::endl;

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
                std::cout << "Enter name: ";
                //std::cin >> name;
                name = 'a' + i + j;
                rowEmployees.push_back(name);
            }
            employees.push_back(rowEmployees);
            
        }

        std::cout << std::endl;
        std::cout << "vec/size: " << employees.size() << std::endl;
        std::cout << "vec/size1: " << employees[1].size();
        std::cout << std::endl;
       
      

        for (int i = 0; i < commands; ++i)
        {
            for (int j = 0; j < employees[i].size(); ++j)
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