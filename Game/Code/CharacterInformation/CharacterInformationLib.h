// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/04 21:29)

#ifndef CHARACTER_INFORMATION_LIB_H
#define CHARACTER_INFORMATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"CharacterInformationD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CharacterInformation.lib")
		#endif // _DEBUG

	#else // !BUILDING_CHARACTER_INFORMATION_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"CharacterInformationStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CharacterInformationStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_CHARACTER_INFORMATION_STATIC

#endif // TCRE_USE_MSVC 

#endif // CHARACTER_INFORMATION_LIB_H
