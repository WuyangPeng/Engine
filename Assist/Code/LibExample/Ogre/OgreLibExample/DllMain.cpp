// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:36)

#include "LibExample/Ogre/OgreLibExample/OgreLibExampleExport.h"

#include "LibExample/Ogre/OgreLibExample/OgreLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OGRE_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(OgreLibExample);

#else // !BUILDING_OGRE_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(OgreLibExample);

#endif // !BUILDING_OGRE_LIB_EXAMPLE_STATIC
