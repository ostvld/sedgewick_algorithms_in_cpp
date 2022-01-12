#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> // close()



#include <limits>
#include <string>
#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
#include <vector>
#include <exception>
#include <list>
#include <algorithm>
#include <signal.h>

#include "tcpServer.h"

void sig_exit(int s)
{
    exit(0);
}


int main(int argc, char *argv[])
{
    signal(SIGINT,sig_exit);
	auto server = std::make_shared<Server::tcpServer>();
    try
    {
        server->upServer();
    }
    catch (const std::exception &e)
    {
        std::cout << "\n exception \t" << e.what() << '\n';
    }
    catch (...)
    {
        std::cout << "exception \t"
                  << "I do not know." << '\n';
    }
    return 0;
}

// gcc -o server s12_1_net.c
#if 0
int main(int argc, char * argv[])
{
    std::cout << "start" << std::endl;
    auto int_min = std::numeric_limits<int>::min();
    auto int_max = std::numeric_limits<int>::max();
    std::cout << "int_min=" << int_min<< "\t" << "int_max=" << int_max <<std::endl;

    auto long_int_min = std::numeric_limits<long int>::min();
    auto long_int_max = std::numeric_limits<long int>::max();
    std::cout << "long_int_min=" << long_int_min<< "\t" << "long_int_max=" << long_int_max <<std::endl;


    auto short_int_min = std::numeric_limits<short int>::min();
    auto short_int_max = std::numeric_limits<short int>::max();
    std::cout << "short_int_min=" << short_int_min<< "\t" << "short_int_max=" << short_int_max <<std::endl;

    auto float_min = std::numeric_limits<float>::min();
    auto float_max = std::numeric_limits<float>::max();
    std::cout << "float_min=" << float_min<< "\t" << "float_max=" << float_max <<std::endl;

    auto double_min = std::numeric_limits<double>::min();
    auto double_max = std::numeric_limits<double>::max();
    std::cout << "double_min=" << double_min<< "\t" << "double_max=" << double_max <<std::endl;

    return 0;
}
#endif

#if 0
template <typename T>

void loopTask(int loopMin, int loopMax, T conteiner)
{
    auto it = conteiner->begin();
    std::advance(it,3);

    for (int iter = loopMin; iter < loopMax; ++iter)
    {

        conteiner->at(iter) = conteiner->size() - 1 - iter;

        std::cout << conteiner->size() << "\t" << conteiner->at(iter) << std::endl;
    }

    std::cout << "revert" << std::endl;

    for (int iter = loopMin; iter < loopMax; ++iter)

    {

        conteiner->at(iter) = conteiner->at(conteiner->at(iter));

        std::cout << conteiner->size() << "\t" << conteiner->at(iter) << std::endl;
    }
}

std::shared_ptr<std::string> runLoopTask()
{
    std::cout << "runLoopTask" << std::endl;

    auto res = std::make_shared<std::string>();

    try
    {

        std::mutex mut;

        auto mas = std::make_shared<std::vector<int>>();

        mas->resize(100, 0);

        std::cout << mas->size() << "\t" << mas->at(0) << std::endl;

        std::thread th1{

            [&]()
            {
                mut.lock();

                loopTask(0, mas->size(), mas);

                mut.unlock();
            }};

        if (th1.joinable())
        {
            th1.join();

            std::cout << "th1.join()" << std::endl;
        }

        for (auto it = mas->begin(); it != mas->end(); ++it)
        {
            res->append(std::to_string(*it) + "\t");
        }
        return res;
    }

    catch (std::exception &e)
    {
        std::cout << "std::exception &e \t" << e.what() << std::endl;
    }
    catch (...)
    {

        std::cout << "something!" << std::endl;
    }
}
#endif
