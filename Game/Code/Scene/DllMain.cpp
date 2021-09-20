// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:14)

#include "Scene/SceneExport.h"

#include "SceneFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SCENE_STATIC

	DLL_MAIN_FUNCTION(Scene);

#else // !BUILDING_SCENE_STATIC

	CORE_TOOLS_MUTEX_INIT(Scene);

#endif // BUILDING_SCENE_STATIC
