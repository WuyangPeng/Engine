// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 10:06)

#ifndef DATABASE_DLL_LIB_H
#define DATABASE_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(_MSC_VER) 

	#ifdef DATABASE_USE_MYSQL 	 

		#ifdef DATABASE_USE_MYSQL_C_API
			#pragma comment(lib,"mysqlclient.lib")	 
		#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR	

		#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
			#pragma comment(lib,"mysqlcppconn8.lib")	 
		#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR	

	#endif // DATABASE_USE_MYSQL
	
#endif // _MSC_VER

#endif // DATABASE_DLL_LIB_H