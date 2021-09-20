// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:02)

#include "LibExample/WxWidgets/WxWidgetsLibExample/WxWidgetsLibExampleExport.h"

#include "LibExample/WxWidgets/WxWidgetsLibExample/WxWidgetsLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(WxWidgetsLibExample);

#else // !BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(WxWidgetsLibExample);

#endif // !BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC
