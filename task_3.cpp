#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>

int main()
{
    std::time_t timer_start;
    std::time_t timer_finish;
    std::time_t delta_sec;
    std::time_t time = std::time(nullptr);
    std::tm* local_time = std::localtime(&time);

    std::cout << "type timer like minutes:seconds : ";
    std::cin >> std::get_time(local_time, "%M:%S");

    delta_sec = local_time->tm_min*60 + local_time->tm_sec;
    time = std::time(nullptr);
    local_time = std::localtime(&time);
    timer_start = std::mktime(local_time);
    timer_finish = timer_start + delta_sec;

    while(true)
    {
        time = std::time(nullptr);
        if(timer_finish <= time)
        {
            std::cout << "ding!" << std::endl;
            break;
        }
        std::cout << timer_finish - time << " seconds left" << std::endl;
        Sleep(1000);
    }

    return 0;
}