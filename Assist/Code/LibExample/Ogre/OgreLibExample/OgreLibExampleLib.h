// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:36)

#ifndef OGRE_LIB_EXAMPLE_LIB_H
#define OGRE_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_OGRE_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"OgreLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OgreLibExample.lib")
		#endif // _DEBUG

	#else // !OGRE_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"OgreLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OgreLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // OGRE_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // OGRE_LIB_EXAMPLE_LIB_H
