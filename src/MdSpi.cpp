#include <MdSpi.h>
#include <log4cxx/logger.h>
#include <cstring>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <string>

using namespace log4cxx;
//static log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("MdSpi");
//std::string Property = "./log4cxx.properties";
//log4cxx::PropertyConfigurator::configure(Property);
static int requestId = 0;
static LoggerPtr logger = Logger::getLogger("MdSpi");
//std::string Property = "./log4cxx.properties";
//log4cxx::PropertyConfigurator::configure(Property);

MdSpi::MdSpi(CThostFtdcMdApi* userApi) {
    m_userApi = userApi;
    //static LoggerPtr logger = Logger::getLogger("MdSpi");
    }

void MdSpi::OnFrontConnected() {
    LOG4CXX_INFO(logger, "connected to front");
    TThostFtdcBrokerIDType  BROKER_ID = "1111";             // 经纪公司代码
    TThostFtdcInvestorIDType INVESTOR_ID = "00016707633";         // 投资者代码
    TThostFtdcPasswordType  PASSWORD = "188888";            // 用户密码
    CThostFtdcReqUserLoginField req;
    std::memset(&req, 0, sizeof(req));
    std::strcpy(req.BrokerID, BROKER_ID);
    std::strcpy(req.UserID, INVESTOR_ID);
    std::strcpy(req.Password, PASSWORD);
    LOG4CXX_INFO(logger, "login...");
    int iResult = m_userApi->ReqUserLogin(&req, requestId);
    if (iResult == 0) {
        LOG4CXX_INFO(logger, "login successfully")
    } else {
        LOG4CXX_ERROR(logger, "login error")
    }

}

void MdSpi::OnFrontDisconnected(int nReason) {
}

void MdSpi::OnHeartBeatWarning(int nTimeLapse) {
}

void MdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
}

void MdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
}

void MdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult) {
        LOG4CXX_WARN(logger, "Error Happend: ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg)
    }
}

void MdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
}

void MdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
}

void MdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {
}



