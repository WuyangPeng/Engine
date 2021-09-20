// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/07 22:36)

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetExport.h"

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PHYSICS_STATIC

	DLL_MAIN_FUNCTION(Physics);

#else // !BUILDING_PHYSICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Physics);

#endif // !BUILDING_PHYSICS_STATIC
