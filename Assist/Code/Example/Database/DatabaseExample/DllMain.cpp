// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/24 0:15)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "Example/Database/DatabaseExample/DatabaseExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(DatabaseExample);

#else // !BUILDING_DATABASE_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(DatabaseExample);

#endif // !BUILDING_DATABASE_EXAMPLE_STATIC
