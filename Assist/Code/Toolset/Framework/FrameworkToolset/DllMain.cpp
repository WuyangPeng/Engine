// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/22 11:52)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	DLL_MAIN_FUNCTION(FrameworkToolset);

#else // !BUILDING_FRAMEWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(FrameworkToolset);

#endif // !BUILDING_FRAMEWORK_STATIC
