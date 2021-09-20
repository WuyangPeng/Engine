// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 11:48)

#ifndef DATABASE_TOOLSET_LIB_H
#define DATABASE_TOOLSET_LIB_H

#include "Database/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DATABASE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DatabaseToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_DATABASE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Database/DatabaseLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DatabaseToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_DATABASE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // DATABASE_TOOLSET_LIB_H
