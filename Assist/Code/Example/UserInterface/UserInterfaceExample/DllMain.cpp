// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 14:00)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(UserInterfaceExample);

#else // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(UserInterfaceExample);

#endif // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
