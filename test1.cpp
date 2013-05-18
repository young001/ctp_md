#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/helpers/exception.h"

using namespace std;
using namespace log4cxx;
using namespace log4cxx::helpers;


int main(int argc, char ** argv)
{
        ///@todo 重定向到文件
   LoggerPtr logger(Logger::getLogger("MyApp"));

   try
   {
       LOG4CXX_INFO(logger, "hello");
       LOG4CXX_DEBUG(logger, "world");

           int x = 0;
           for ( x; x < 100; x++ )
           {
                   LOG4CXX_INFO(logger,"world");
           }
   }
   catch (Exception&)
   {

   }
   return 0;
}

