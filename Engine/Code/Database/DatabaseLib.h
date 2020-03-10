// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:32)

#ifndef DATABASE_LIB_H
#define DATABASE_LIB_H

#include "Macro/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DATABASE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Database.lib")
		#endif // _DEBUG

	#else // !BUILDING_DATABASE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DatabaseStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_DATABASE_STATIC

#endif // TCRE_USE_MSVC 
 
#endif // DATABASE_LIB_H