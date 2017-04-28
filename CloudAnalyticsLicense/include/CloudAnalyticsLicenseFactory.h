#pragma once
/*=============================================================================

Library: CloudLicenseAndAnalyticsServices

=============================================================================*/

#ifndef CLOUDLICENSEANALYTICS_SERVICEINTERFACE_H
#define CLOUDLICENSEANALYTICS_SERVICEINTERFACE_H


#include "CloudLibExp.h"
#include <string>
#include "LicenseServiceInterface.h"
#include "AnalyticsServiceInterface.h"
#include <memory>


namespace cloudanllicservices {

		typedef enum CLOUDANLLICLIB_API CLOUDSEVICEPROVIDER
		{
			NALPEIRON = 0,
		} CLOUDSEVICEPROVIDER;


		/**
		* \CADS Cloud Licensing and Analytics Service
		*
		* A factory for creating cloud Licensing and Analytics Service instances.
		*
		* @remarks The retuned service object requires property to be set before using it.
		*/

		class CLOUDANLLICLIB_API LicenseAnalyticsfactory
		{
		public:
			/**
			* Create a new License Service instance.
			*
			* @param CLOUDSEVICEPROVIDER The cloud license service provider who actually implements the services has to be given here to configure the new license service instance. 
			* Currently we support Nalpeiron Cloud licenseing service.
			* 
			* @return A new, configured license service instance.
			*/
			static std::shared_ptr<licenseservice::LicenseServiceInterface>  GetLicenseService(CLOUDSEVICEPROVIDER);

			/**
			* Create a new Analytics Service instance.
			*
			* @param CLOUDSEVICEPROVIDER The cloud analytics service provider who actually implements the services has to be given here to configure the new analytics service instance.
			* Currently we support Nalpeiron Cloud analytics service.
			*
			* @return A new, configured analytics service instance.
			*/
			static std::shared_ptr<analyticsservice::AnalyticsServiceInterface> GetAnalyticsService(CLOUDSEVICEPROVIDER);
		};

	extern "C"
	{
		void* CreateAnalyticsModule();
	}
}

#endif // CLOUDLICENSEANALYTICS_SERVICEINTERFACE_H

