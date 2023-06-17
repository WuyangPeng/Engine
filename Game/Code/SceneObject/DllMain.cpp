///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:16)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObjectFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_OBJECT_STATIC

DLL_MAIN_FUNCTION(SceneObject);

#else  // !BUILDING_SCENE_OBJECT_STATIC

CORE_TOOLS_MUTEX_INIT(SceneObject);

#endif  // BUILDING_SCENE_OBJECT_STATIC
