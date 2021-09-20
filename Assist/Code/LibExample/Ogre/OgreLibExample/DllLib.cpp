// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:36)

#include "LibExample/Ogre/OgreLibExample/OgreLibExampleExport.h"

#include "LibExample/Ogre/OgreLibExample/OgreLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_OGRE_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_OGRE_LIB_EXAMPLE_STATIC

	namespace OgreLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_OGRE_LIB_EXAMPLE_STATIC
