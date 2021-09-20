// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:14)

#include "Scene/SceneExport.h"

#include "SceneFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SCENE_STATIC

	DLL_MAIN_FUNCTION(Scene);

#else // !BUILDING_SCENE_STATIC

	CORE_TOOLS_MUTEX_INIT(Scene);

#endif // BUILDING_SCENE_STATIC
