#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct bDay
{
    std::string name = "none";
    std::time_t time;
};

int main()
{
    std::vector<bDay> list;
    bDay user_input_date;
    std::time_t time = std::time(nullptr);
    std::tm* local = std::localtime(&time);
    std::string user_input;

    while (true) {
        std::cout << "Type name or 'end' to exit: ";
        std::cin >> user_input;
        if (user_input == "end") break; //expression to exit
        user_input_date.name = user_input;

        std::cout << "Type bday date like yyyy/mm/dd : ";
        std::cin >> std::get_time(local, "%Y/%m/%d");
        user_input_date.time = std::mktime(local);

        list.push_back(user_input_date);
    }

    time = std::time(nullptr);
    local = std::localtime(&time);

    std::cout << local->tm_mday << " " << local->tm_mon << std::endl;

    for(int i = 0; i < list.size(); i++)
    {
        std::tm* tmp = std::localtime(&list[i].time);

        if(local->tm_mday == tmp->tm_mday && local->tm_mon == tmp->tm_mon)
        {
            std::cout << local->tm_mday << " " << local->tm_mon << std::endl;

            std::cout << "BDay today: " << list[i].name << " " << tmp->tm_mday << " " << tmp->tm_mon << std::endl;
        }

    }

    return 0;
}