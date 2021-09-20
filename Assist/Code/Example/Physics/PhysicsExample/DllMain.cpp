// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 16:00)

#include "Example/Physics/PhysicsExample/PhysicsExampleExport.h"

#include "Example/Physics/PhysicsExample/PhysicsExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PHYSICS_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(PhysicsExample);

#else // !BUILDING_PHYSICS_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(PhysicsExample);

#endif // !BUILDING_PHYSICS_EXAMPLE_STATIC
