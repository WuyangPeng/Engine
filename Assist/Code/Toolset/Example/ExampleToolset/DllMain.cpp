// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
// 
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.0.0 (2019/09/23 10:11)

#include "Toolset/Example/ExampleToolset/ExampleToolsetExport.h"

#include "Toolset/Example/ExampleToolset/ExampleToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(Example);

#else // !BUILDING_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(Example);

#endif // !BUILDING_EXAMPLE_STATIC
