// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 14:44)

#include "Physics/PhysicsExport.h"

#include "Physics/PhysicsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PHYSICS_STATIC

	DLL_MAIN_FUNCTION(Physics);

#else // !BUILDING_PHYSICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Physics);

#endif // !BUILDING_PHYSICS_STATIC