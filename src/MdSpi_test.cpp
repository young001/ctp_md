#include "MdSpi.h"
#include <ThostFtdcMdApi.h>
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/propertyconfigurator.h>
#include <string>

//char FRONT_ADDR[] = "tcp://123.124.247.2:32111";
char FRONT_ADDR[] = "tcp://asp-sim2-md1.financial-trading-platform.com:26213";

int main() {
    //log4cxx::BasicConfigurator::configure();
    std::string Property = "./log4cxx.properties";
    log4cxx::PropertyConfigurator::configure(Property);
    log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("MdSpi_test");

    LOG4CXX_INFO(logger, "starting MdSpi_test")
    CThostFtdcMdApi* pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();          // 创建UserApi
    CThostFtdcMdSpi* pUserSpi = new MdSpi(pUserApi);
    
    LOG4CXX_INFO(logger, "Register Spi")
    pUserApi->RegisterSpi(pUserSpi);                        // 注册事件类

    LOG4CXX_INFO(logger, "Register Front")
    pUserApi->RegisterFront(FRONT_ADDR);                    // connect

    LOG4CXX_INFO(logger, "Init")
    pUserApi->Init();

    pUserApi->Join();
    return 0;
}


