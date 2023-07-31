///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:13)

#include "Scene/SceneExport.h"

#include "SceneFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_STATIC

DLL_MAIN_FUNCTION(Scene);

#else  // !BUILDING_SCENE_STATIC

CORE_TOOLS_MUTEX_INIT(Scene);

#endif  // BUILDING_SCENE_STATIC
