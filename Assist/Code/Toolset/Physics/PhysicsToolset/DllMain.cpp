///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:58)

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetFwd.h"

#ifndef BUILDING_PHYSICS_STATIC

DLL_MAIN_FUNCTION(Physics);

#else  // !BUILDING_PHYSICS_STATIC

CORE_TOOLS_MUTEX_INIT(Physics);

#endif  // !BUILDING_PHYSICS_STATIC
