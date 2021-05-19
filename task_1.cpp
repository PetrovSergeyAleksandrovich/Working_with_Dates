#include <iostream>
#include <ctime>
#include <vector>

class userAction
{
public:
    std::string begin_ = "begin";
    std::string end_ = "end";
    std::string status_ = "status";
    std::string close_ = "close";
};

struct data_manager
{
    std::string task_name = "none";
    double task_time = 0;
};

int main() {

    std::vector<data_manager> tasks_list = {};
    data_manager current_task;
    userAction user_action;
    std::time_t time_start, time_end;
    bool task_watchdog = false;
    double delta_time = 0;
    std::string user_input, user_discription;
    double hour_divider = 3600.f;


    while (user_input != user_action.close_)
    {
        std::cout << "Type action begin/end/status/close: ";
        std::cin >> user_input;

        if(user_input == user_action.begin_)
        {
            if(task_watchdog)
            {
                time_end = std::time(nullptr);
                delta_time = difftime(time_end,time_start);
                current_task.task_name = user_discription;
                current_task.task_time = delta_time / hour_divider;
                tasks_list.push_back(current_task);
                task_watchdog = false;

            }
            std::cout << "type name for your task: " << std::endl;
            std::cin >> user_discription;

            time_start = std::time(nullptr);
            task_watchdog = true;
        }

        if(user_input == user_action.end_)
        {
            time_end = std::time(nullptr);
            delta_time = difftime(time_end,time_start);
            current_task.task_name = user_discription;
            current_task.task_time = delta_time / hour_divider;
            tasks_list.push_back(current_task);
            task_watchdog = false;
        }

        if(user_input == user_action.status_)
        {
            if(tasks_list.size() == 0) std::cout << "no finished tasks yet" << std::endl;
            else
            {
                for(int i = 0; i < tasks_list.size(); i++)
                {
                    std::cout << tasks_list[i].task_name << " " << tasks_list[i].task_time << " hours" << std::endl;
                }
                std::cout << std::endl;
            }

            if(task_watchdog)
            {
                std:: cout << "current task: " << user_discription << " "
                    << difftime(std::time(nullptr),time_start) / hour_divider << " hours" << std::endl;
            }


        }

    }

    std::cout << "exited" << std::endl;

    return 0;
}


