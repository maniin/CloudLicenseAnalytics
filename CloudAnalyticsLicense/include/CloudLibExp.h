#pragma once
#    ifdef CLOUDANLLICLIB_EXPORTS
#        define CLOUDANLLICLIB_API __declspec(dllexport)
#		 define EXPIMP_TEMPLATE
#    else
#        define CLOUDANLLICLIB_API __declspec(dllimport)
#		 define EXPIMP_TEMPLATE extern
#    endif