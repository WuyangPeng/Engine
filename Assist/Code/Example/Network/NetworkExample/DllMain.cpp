// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/23 23:19)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "Example/Network/NetworkExample/NetworkExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(NetworkExample);

#else // !BUILDING_NETWORK_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(NetworkExample);

#endif // !BUILDING_NETWORK_EXAMPLE_STATIC
