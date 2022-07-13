///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 16:10)

#include "Example/Physics/PhysicsExample/PhysicsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Physics/PhysicsExample/PhysicsExampleFwd.h"

#ifndef BUILDING_PHYSICS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(PhysicsExample);

#else  // !BUILDING_PHYSICS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(PhysicsExample);

#endif  // !BUILDING_PHYSICS_EXAMPLE_STATIC
