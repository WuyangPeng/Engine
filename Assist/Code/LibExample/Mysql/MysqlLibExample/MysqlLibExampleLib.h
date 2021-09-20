// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 1:54)

#ifndef MYSQL_LIB_EXAMPLE_LIB_H
#define MYSQL_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MYSQL_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MysqlLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MysqlLibExample.lib")
		#endif // _DEBUG

	#else // !MYSQL_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MysqlLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MysqlLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // MYSQL_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MYSQL_LIB_EXAMPLE_LIB_H
