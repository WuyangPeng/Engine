// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 1:46)

#include "Toolset/LibExample/LibExampleToolset/LibExampleToolsetExport.h"

#include "Toolset/LibExample/LibExampleToolset/LibExampleToolset.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_LIB_EXAMPLE_STATIC

	namespace LibExampleToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_LIB_EXAMPLE_STATIC
