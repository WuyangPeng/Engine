// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 20:11)

#include "LibExample/DirectX/DirectXLibExample/DirectXLibExampleExport.h"

#include "LibExample/DirectX/DirectXLibExample/DirectXLibExample.h" 

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_DIRECTX_LIB_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_DIRECTX_LIB_EXAMPLE_STATIC

	namespace DirectXLibExample
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_DIRECTX_LIB_EXAMPLE_STATIC
