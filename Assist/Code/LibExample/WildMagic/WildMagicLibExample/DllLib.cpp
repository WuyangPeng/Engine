// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 14:37)

#include "LibExample/WildMagic/WildMagicLibExample/WildMagicLibExampleExport.h"

#include "LibExample/WildMagic/WildMagicLibExample/WildMagicLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC

	namespace WildMagicLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC
