#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct bDay
{
    std::string name = "none";
    int year;
    int month;
    int day;
};

int main()
{
    std::vector<bDay> list = {};
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
        user_input_date.year = local->tm_year;
        user_input_date.month= local->tm_mon;
        user_input_date.day = local->tm_mday;

        list.push_back(user_input_date);
    }

    std::time_t current_date = std::time(nullptr);
    std::tm* current_date_local = std::localtime(&current_date);

    std::cout << "\nLIST of future BDays:\n";

    int delta_days = current_date_local->tm_mday - list[0].day;
    int delta_months = current_date_local->tm_mon - list[0].month;
    std::string closest_bday = list[0].name;

    for(int i = 0; i < list.size(); i++)
    {

        if(list[i].month < current_date_local->tm_mon) continue;
        else if (list[i].month == current_date_local->tm_mon) if(list[i].day < current_date_local->tm_mday) continue;

        if(list[i].month == current_date_local->tm_mon && list[i].day == current_date_local->tm_mday)
        {
            std::cout << "Happy Birthday TODAY to " << list[i].name << std::endl;
        }

        // search for nearest b-day
        if(current_date_local->tm_mon - list[i].month < delta_months)
        {
            closest_bday = list[i].name;
            delta_months = current_date_local->tm_mon - list[i].month;
        }
        else if (current_date_local->tm_mon - list[i].month == delta_months)
        {
            if(current_date_local->tm_mday - list[i].day < delta_days)
            {
                closest_bday = list[i].name;
                delta_days = current_date_local->tm_mday - list[i].day;
            }
        }

    }

    //print nearest b-day for one or more people
    for(int i = 0; i < list.size(); i++)
    {
        int tmp_day = 0;
        int tmp_month = 0;

        if(list[i].name == closest_bday)
        {
            std::cout << "Nearest bday: " << list[i].name << " " << list[i].day << " " << list[i].month << std::endl;
            tmp_day = list[i].day;
            tmp_month = list[i].month;
            for(int j = 0; j < list.size(); j++)
            {
                if(list[j].day == tmp_day && list[j].month == tmp_month && list[j].name != closest_bday)
                {
                    std::cout << "Nearest bday: " << list[i].name << " " << list[i].day << " " << list[i].month << std::endl;
                }

            }
        }
    }


    return 0;
}
