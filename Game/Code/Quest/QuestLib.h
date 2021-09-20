// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 22:00)

#ifndef QUEST_LIB_H
#define QUEST_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_QUEST_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"QuestD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Quest.lib")
		#endif // _DEBUG

	#else // !BUILDING_QUEST_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"QuestStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"QuestStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_QUEST_STATIC

#endif // TCRE_USE_MSVC 

#endif // QUEST_LIB_H
