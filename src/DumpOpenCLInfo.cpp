/*
 * @Author: Zhou Zijian 
 * @Date: 2023-03-11 00:00:44 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-01-19 00:45:47
 */

#include <argparse/argparse.hpp>
#include "define.h"
#include "InfoShowConsole.h"
#include "InfoShowJson.h"

int main(int argc, char *argv[])
{
    LOGD("%s %d.%d.%d.%d %s", PROJECT_NAME, VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TWEAK, COMPILE_TIME);

    argparse::ArgumentParser program("opencl info");

    program.add_argument("--format")
        .required()
        .help("specify the output format. [console or json]")
        .default_value(std::string{"console"});

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    if (program.get<std::string>("--format") == "console") {
        std::unique_ptr<InfoShow> infoShow(new (std::nothrow) InfoShowConsole);
        if (infoShow) {
            infoShow->Run();
        }
    } else if (program.get<std::string>("--format") == "json") {
        std::unique_ptr<InfoShow> infoShow(new (std::nothrow) InfoShowJson);
        if (infoShow) {
            infoShow->Run();
        }
    }
    return OK;
}