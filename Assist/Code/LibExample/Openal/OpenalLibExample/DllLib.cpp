// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:32)

#include "LibExample/Openal/OpenalLibExample/OpenalLibExampleExport.h"

#include "LibExample/Openal/OpenalLibExample/OpenalLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_OPENAL_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_OPENAL_LIB_EXAMPLE_STATIC

	namespace OpenalLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_OPENAL_LIB_EXAMPLE_STATIC
