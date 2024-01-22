/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:49)

#include "Physics/PhysicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Physics/PhysicsFwd.h"

#ifndef BUILDING_PHYSICS_STATIC

DLL_MAIN_FUNCTION(Physics);

#else  // !BUILDING_PHYSICS_STATIC

CORE_TOOLS_MUTEX_INIT(Physics);

#endif  // !BUILDING_PHYSICS_STATIC