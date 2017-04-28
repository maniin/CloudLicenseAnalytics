#pragma once
/*=============================================================================

Library: CloudLicenseServices

=============================================================================*/

#ifndef CLOUDLICENSE_SERVICEINTERFACE_H
#define CLOUDLICENSE_SERVICEINTERFACE_H


#include "CloudLibExp.h"
#include <string>


namespace cloudanllicservices {

	namespace licenseservice {


		typedef enum LicenseType : uint32_t
		{
			Unknown = 0,
			Trial = 2,
			Permenant_Node_locked = 3,
			Permenant_Floating = 4,
			Subscription_Node_locked = 5,
			Subscription_Floating = 6

		}LicenseType;


		/**
		* \CADS Cloud Licensing Service
		*
		* This is the interface for cloud Licensing Service which is exposed to client. Any cloud license service provider
		* can implement this interface and can avail the instances through factory.
		*
		* @remarks This service object requires property to be set before using it.
		*/

		class CLOUDANLLICLIB_API LicenseServiceInterface
		{
		public:
			/**
			* Sets the License Service property for the instance.
			*
			****************************************************************************************************************
			* This method must be called before calling any of the method in this class, after construction of this object.
			****************************************************************************************************************
			*
			* @param ServiceProperties, Client must initialize the ServiceProperty object and pass as an argument.
			* All parameters of ServiceProperties are must.
			*
			* @return True if the requested cloud service starts. false if it fails to initialize the cloud service.
			*/
			bool virtual SetServiceProperties(std::string applicationname, std::string licenseCode, std::string buildversion, std::string buildnumber, void* AnalyticsServ = nullptr) = 0;

			/**
			* This is simplified interface to Check and Get the Licensefor the application (Based on the license code)
			*
			* Recommended to use this from client program. It manages everything internally.
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*/
			bool virtual CheckAndGetLicense() = 0;
			/**
			* Get the License status for the application (Based on the license code)
			*
			* @outparam License status of the implmentor(Nalpeiron) service is returned.
			*			Example, "3" for license Activated
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*/
			bool virtual GetLicenseStatus(int& status) = 0;
			/**
			* Activate the License code.
			*
			* @param "licenseCode" if this parameter given, this license code is used for license activation
			*		 if it is empty, "ServiceProperties" license code will be used by default.
			*
			* @outparam License status of the implmentor(Nalpeiron) service is returned.
			*			Example, "3" for license Activated
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*/
			bool virtual GetLicense(int& status, std::string licenseCode = "") = 0;
			/**
			* DeActivate/ Unlicense the License code.
			*
			* @param "licenseCode" if this parameter given, this license code is used for license deactivation
			*		 if it is empty, "ServiceProperties" license code will be used by default.
			*
			* @outparam License status of the implmentor(Nalpeiron) service is returned.
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*/
			bool virtual ReturnLicense(int& status, std::string licenseCode = "") = 0;
			/**
			* Get the Feature status of the application (Validate the feature usage)
			*
			* @outparam Feature status of the implmentor(Nalpeiron) service is returned.
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*/
			bool virtual GetFeatureStatus(int& featureStatus, std::string	featName = "") = 0;
			/**
			* Activate the feature usage, Mainly for floating license type.
			*
			* @param "featName"  this the feature code used in the product license to be get validated
			*		 
			* @param "licenseCode" for this license code the feature will be validated.
			*    if it is empty, "ServiceProperties" license code will be used by default.
			*
			* @outparam Feature status of the implmentor(Nalpeiron) service is returned.
			*
			* @return True if the requested cloud service successfully get the status, false if it fails to get the status from cloud service.
			*		 Number of available feature license will be reduced.
			*/
			bool virtual CheckoutFeatureLicense(int& featureStatus, std::string featName = "", std::string licenseCode = "") = 0;
			/**
			* Returned the feature license used, Mainly for floating license type.
			*
			* @param "featName"  this the feature code used in the product license to be get validated
			*
			* @param "licenseCode" for this license code the feature will be validated.
			*    if it is empty, "ServiceProperties" license code will be used by default.
			*
			* @return True if the requested cloud service successfully returned the license, false if it fails to return the license to cloud service.
			*		 Number of available feature license will be incredmented.
			*/
			bool virtual ReturnFeatureLicense(std::string featName = "", std::string licenseCode = "") = 0;
			/**
			* Get the License Type
			*
			* @return license type based on the license code set earlier. Example, Node-Locked
			*/
			LicenseType virtual GetLicenseType() = 0;
			//std::string virtual GetLicenseExpiryDate() = 0;
			//std::string virtual GetLicenseExpirySeconds() = 0;

		protected:

			virtual ~LicenseServiceInterface() {};

		};




	}
}

#endif // CLOUDLICENSE_SERVICEINTERFACE_H

