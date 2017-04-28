# CloudLicenseAnalytics

This is Analyitcs module to collect the application usage and collecting system information

How to Use:

<code>

    #include "CloudAnalyticsTest.h"
    #include <synchapi.h>
    #include <iostream>

    #include "memory.h"

    using namespace cloudanllicservices;

    void testCloudAnalytics()
        {
	         try
	           {
                auto NlpAnalyticsServ =  LicenseAnalyticsfactory::GetAnalyticsService(CLOUDSEVICEPROVIDER::NALPEIRON);
                NlpAnalyticsServ->SetServiceProperties("A3DMAX", "489100000029034215", "2017.1.0", "1122", nullptr);
                NlpAnalyticsServ->ApplicationLaunch();
                Sleep(5000);   
                NlpAnalyticsServ->ApplicationExit();	
                }
                catch (std::exception& ex)
                {
                std::cout<<ex.what()<< std::endl;
                }
       }
       
  </code>
