#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct bDay
{
    std::string name = "none";
    int year = 0;
    int month = 0;
    int day = 0;
};

int main()
{
    std::vector<bDay> list = {};
    bDay user_input_date;
    bDay nearest_bday;
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
        user_input_date.year = local->tm_year;
        user_input_date.month= local->tm_mon;
        user_input_date.day = local->tm_mday;

        list.push_back(user_input_date);
    }

    // search for any first future bday in the list to initialise search
    std::time_t current_date = std::time(nullptr);
    std::tm* current_date_local = std::localtime(&current_date);

    for(int i = 0; i < list.size(); i++)
    {
        if(list[i].month > current_date_local->tm_mon)
        {
            nearest_bday = list[i];
            break;
        }
        else if (list[i].month == current_date_local->tm_mon)
        {
            if(list[i].day > current_date_local->tm_mday)
            {
                nearest_bday = list[i];
                break;
            }
        }
    }

    // search for nearest b-day and bday for today
    for(int i = 0; i < list.size(); i++)
    {

        if(list[i].month < current_date_local->tm_mon) continue;
        else if (list[i].month == current_date_local->tm_mon) if(list[i].day < current_date_local->tm_mday) continue;

        if(list[i].month == current_date_local->tm_mon && list[i].day == current_date_local->tm_mday)
        {
            std::cout << "\n~Happy Birthday TODAY to :" << list[i].name << std::endl;
            continue;
        }

        // search for nearest b-day
        if(list[i].month < nearest_bday.month)
        {
            nearest_bday = list[i];
        }
        else if (list[i].month == nearest_bday.month)
        {
            if(list[i].day < nearest_bday.day)
            {
                nearest_bday = list[i];
            }
        }
    }

    //Printing results
    if(nearest_bday.name != "none")
    {
        std::cout << "Nearest bdays:\n" << nearest_bday.name << " "
                  << nearest_bday.day << " " << nearest_bday.month+1 << std::endl;
    }
    //print nearest b-day for one or more people if exists in the list for the nearest day
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i].day == nearest_bday.day && list[i].month == nearest_bday.month && list[i].name != nearest_bday.name)
        {
            std::cout << list[i].name << " "
            << list[i].day << " " << list[i].month+1 << std::endl;
        }
    }

    return 0;
}
