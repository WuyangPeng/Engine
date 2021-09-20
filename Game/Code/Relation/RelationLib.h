// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:53)

#ifndef RELATION_LIB_H
#define RELATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RELATION_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"RelationD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Relation.lib")
		#endif // _DEBUG

	#else // !BUILDING_RELATION_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"RelationStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RelationStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RELATION_STATIC

#endif // TCRE_USE_MSVC 

#endif // RELATION_LIB_H
