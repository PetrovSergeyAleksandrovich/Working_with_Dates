#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct bDay
{
    std::string name = "none";
    std::tm* date;
};

int main()
{
    std::vector<bDay> list;
    bDay user_input_date;
    std::time_t user_time_input = std::time(nullptr);
    std::tm* local = std::localtime(&user_time_input);
    std::string user_input;

    while(true)
    {
        std::cout << "Type name or 'end' to exit: ";
        std::cin >> user_input;
        if(user_input == "end") break; //expression to exit
        user_input_date.name = user_input;

        std::cout << "Type bday date like yyyy/mm/dd : ";
        std::cin >> std::get_time(local, "%Y/%m/%d");
        user_input_date.date = local;

        list.push_back(user_input_date);

        std::cout << "your input: " << list[0].name << " " << list[0].date->tm_mday
                  << " " << list[0].date->tm_mon << std::endl;
    }

    std::time_t current_date = std::time(nullptr);
    std::tm* current_date_local = std::localtime(&current_date);

    std::cout << "LIST:\n";
    for(int i = 0; i < list.size(); i++)
    {

        std::cout << list[i].date->tm_mday << std::endl;

/*        if((current_date_local->tm_mday < list[i].date->tm_mday) && (current_date_local->tm_mon <= list[i].date->tm_mon))
        {
            std::cout << list[i].name << " " << std::put_time(list[i].date, "%Y/%m/%d") << std::endl;
        }*/

    }

    return 0;
}
