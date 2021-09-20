// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:16)

#include "LibExample/Irrlicht/IrrlichtLibExample/IrrlichtLibExampleExport.h"

#include "LibExample/Irrlicht/IrrlichtLibExample/IrrlichtLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC

	namespace IrrlichtLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC
