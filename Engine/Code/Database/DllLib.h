// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:31)

#ifndef DATABASE_DLL_LIB_H
#define DATABASE_DLL_LIB_H

#include "Macro/UserMacro.h"

#if defined(_MSC_VER) 

	#ifdef DATABASE_USE_MYSQL 	 

		#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
			#pragma comment(lib,"mysqlcppconn8.lib")	 
		#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR	

	#endif // DATABASE_USE_MYSQL
	
#endif // _MSC_VER

#endif // DATABASE_DLL_LIB_H