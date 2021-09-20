// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 0:50)

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExampleExport.h"

#include "Example/ResourceManager/ResourceManagerExample/ResourceManagerExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

	namespace ResourceManagerExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC
