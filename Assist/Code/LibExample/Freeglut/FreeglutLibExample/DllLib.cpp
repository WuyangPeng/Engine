// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 12:52)

#include "LibExample/Freeglut/FreeglutLibExample/FreeglutLibExampleExport.h"

#include "LibExample/Freeglut/FreeglutLibExample/FreeglutLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC

	namespace FreeglutLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC
