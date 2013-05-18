#include "log4cxx/logger.h"
#include "log4cxx/propertyconfigurator.h"

using namespace std;
using namespace log4cxx;
using namespace log4cxx::helpers;


int main(int argc, char *argv[])
{
        ///@todo 重定向到文件
    string trace = "fa";
    string Property = "./log4cxx.properties";
    log4cxx::PropertyConfigurator::configure(Property);
    LoggerPtr logger = Logger::getLogger(trace);
    logger->info(("How to use?"));
    LOG4CXX_INFO(logger, ("你说hello"));

    for(int i = 0; i < 2; i++)
    {
        LOG4CXX_DEBUG(logger, "DEBUG");
        LOG4CXX_INFO(logger, "INFO"); 
        LOG4CXX_WARN(logger, "WARN");
        LOG4CXX_ERROR(logger, "ERROR");
    }

    return 0;
}
