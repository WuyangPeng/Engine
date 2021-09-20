// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 20:11)

#include "LibExample/DirectX/DirectXLibExample/DirectXLibExampleExport.h"

#include "LibExample/DirectX/DirectXLibExample/DirectXLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DIRECTX_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(DirectXLibExample);

#else // !BUILDING_DIRECTX_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(DirectXLibExample);

#endif // !BUILDING_DIRECTX_LIB_EXAMPLE_STATIC
