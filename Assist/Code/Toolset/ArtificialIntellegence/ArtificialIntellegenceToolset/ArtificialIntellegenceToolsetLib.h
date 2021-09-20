// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/08 21:28)

#ifndef ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H
#define ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H

#include "ArtificialIntellegence/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegenceToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "ArtificialIntellegence/ArtificialIntellegenceLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegenceToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H
