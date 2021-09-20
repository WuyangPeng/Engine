// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:24)

#ifndef MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_LIB_H
#define MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MysqlConnectorCppLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MysqlConnectorCppLibExample.lib")
		#endif // _DEBUG

	#else // !MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MysqlConnectorCppLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MysqlConnectorCppLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MYSQL_CONNECTOR_CPP_LIB_EXAMPLE_LIB_H
