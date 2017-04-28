#pragma once

#ifndef CLOUDANALYTICS_SERVICEINTERFACE_H
#define CLOUDANALYTICS_SERVICEINTERFACE_H

/*=============================================================================

Library: CloudAnalyticsServices

=============================================================================*/

#include "CloudLibExp.h"
#include <string>
#include <memory>

namespace cloudanllicservices {

	namespace analyticsservice {

		class CLOUDANLLICLIB_API AnalyticsServiceInterface
		{
		public:
			bool virtual SetServiceProperties(std::string applicationname, std::string licenseCode, std::string buildversion, std::string buildnumber, void* LicenseServ = nullptr) = 0;
			bool virtual ApplicationLaunch(std::string clientData = "") = 0;
			bool virtual ApplicationExit(std::string clientData = "") = 0;
			bool virtual CollectSystemInfo(std::string clientData = "") = 0;
			bool virtual ApplicationStart(std::string clientData = "") = 0;
			bool virtual ApplicationEnd(std::string clientData = "") = 0;
			bool virtual SendCache() = 0;
			bool virtual FeatureStart(std::string featCode = "",std::string clientData = "") = 0;
			bool virtual FeatureEnd(std::string featCode = "",std::string clientData = "") = 0;
			bool virtual Login(std::string clientData = "") = 0;
			bool virtual Logout(std::string clientData = "") = 0;
		protected:
			virtual ~AnalyticsServiceInterface() {};

		};

	}

}

#endif // CLOUDANALYTICS_SERVICEINTERFACE_H



