// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:28)

#include "LibExample/Freealut/FreealutLibExample/FreealutLibExampleExport.h"

#include "LibExample/Freealut/FreealutLibExample/FreealutLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_FREEALUT_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_FREEALUT_LIB_EXAMPLE_STATIC

	namespace FreealutLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FREEALUT_LIB_EXAMPLE_STATIC
