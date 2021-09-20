// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:46)

#ifndef STATUSLIB_H
#define STATUSLIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_STATUSSTATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"StatusD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Status.lib")
		#endif // _DEBUG

	#else // !BUILDING_STATUSSTATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"StatusStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"StatusStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_STATUSSTATIC

#endif // TCRE_USE_MSVC 

#endif // STATUSLIB_H
