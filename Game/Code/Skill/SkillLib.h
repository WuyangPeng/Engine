// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:38)

#ifndef SKILL_LIB_H
#define SKILL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SKILL_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SkillD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Skill.lib")
		#endif // _DEBUG

	#else // !BUILDING_SKILL_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"SkillStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SkillStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SKILL_STATIC

#endif // TCRE_USE_MSVC 

#endif // SKILL_LIB_H
