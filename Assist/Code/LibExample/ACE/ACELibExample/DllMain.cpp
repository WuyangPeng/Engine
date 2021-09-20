// Copyright (c) 2011-2019
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.0.3 (2019/09/30 23:03)

#include "LibExample/ACE/ACELibExample/ACELibExampleExport.h"

#include "LibExample/ACE/ACELibExample/ACELibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACE_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ACELibExample);

#else // !BUILDING_ACE_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ACELibExample);

#endif // !BUILDING_ACE_LIB_EXAMPLE_STATIC
