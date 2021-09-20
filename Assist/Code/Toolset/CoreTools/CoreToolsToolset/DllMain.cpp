// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.0 (2020/01/02 22:57)

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetExport.h"

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

	DLL_MAIN_FUNCTION(CoreTools);

#else // !BUILDING_CORE_TOOLS_STATIC

	CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif // !BUILDING_CORE_TOOLS_STATIC
