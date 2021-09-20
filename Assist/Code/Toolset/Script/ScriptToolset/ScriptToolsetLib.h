// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 11:57)

#ifndef SCRIPT_TOOLSET_LIB_H
#define SCRIPT_TOOLSET_LIB_H

#include "Script/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCRIPT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCRIPT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Script/ScriptLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCRIPT_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SCRIPT_TOOLSET_LIB_H
