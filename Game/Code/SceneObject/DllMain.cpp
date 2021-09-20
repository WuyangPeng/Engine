// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/03 21:50)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObjectFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SCENE_OBJECT_STATIC

	DLL_MAIN_FUNCTION(SceneObject);

#else // !BUILDING_SCENE_OBJECT_STATIC

	CORE_TOOLS_MUTEX_INIT(SceneObject);

#endif // BUILDING_SCENE_OBJECT_STATIC
