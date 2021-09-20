// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 13:56)

#include "LibExample/Opencv/OpencvLibExample/OpencvLibExampleExport.h"

#include "LibExample/Opencv/OpencvLibExample/OpencvLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OPENCV_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(OpencvLibExample);

#else // !BUILDING_OPENCV_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(OpencvLibExample);

#endif // !BUILDING_OPENCV_LIB_EXAMPLE_STATIC
