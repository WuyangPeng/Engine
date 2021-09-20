// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.0 (2020/01/05 11:58)

#include "Toolset/Script/ScriptToolset/ScriptToolsetExport.h"

#include "Toolset/Script/ScriptToolset/ScriptToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCRIPT_STATIC

	DLL_MAIN_FUNCTION(Script);

#else // !BUILDING_SCRIPT_STATIC

	CORE_TOOLS_MUTEX_INIT(Script);

#endif // !BUILDING_SCRIPT_STATIC
