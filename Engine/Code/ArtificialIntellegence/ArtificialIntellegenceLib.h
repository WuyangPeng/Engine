// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 10:06)

#ifndef ARTIFICIAL_INTELLEGENCE_LIB_H
#define ARTIFICIAL_INTELLEGENCE_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegence.lib")
		#endif // _DEBUG

	#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegenceStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ARTIFICIAL_INTELLEGENCE_LIB_H