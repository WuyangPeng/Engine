// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 0:19)

#include "LibExample/Glew/GlewLibExample/GlewLibExampleExport.h"

#include "LibExample/Glew/GlewLibExample/GlewLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_GLEW_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_GLEW_LIB_EXAMPLE_STATIC

	namespace GlewLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_GLEW_LIB_EXAMPLE_STATIC
