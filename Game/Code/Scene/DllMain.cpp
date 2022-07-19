///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 18:18)

#include "Scene/SceneExport.h"

#include "SceneFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_STATIC

DLL_MAIN_FUNCTION(Scene);

#else  // !BUILDING_SCENE_STATIC

CORE_TOOLS_MUTEX_INIT(Scene);

#endif  // BUILDING_SCENE_STATIC
