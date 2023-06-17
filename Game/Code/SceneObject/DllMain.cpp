///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:16)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObjectFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_OBJECT_STATIC

DLL_MAIN_FUNCTION(SceneObject);

#else  // !BUILDING_SCENE_OBJECT_STATIC

CORE_TOOLS_MUTEX_INIT(SceneObject);

#endif  // BUILDING_SCENE_OBJECT_STATIC
