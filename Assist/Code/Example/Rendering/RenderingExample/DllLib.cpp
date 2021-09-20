// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 1:13)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "Example/Rendering/RenderingExample/RenderingExample.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_RENDERING_EXAMPLE_STATIC

	namespace RenderingExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_RENDERING_EXAMPLE_STATIC
