// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/03 21:50)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObjectFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SCENE_OBJECT_STATIC

	DLL_MAIN_FUNCTION(SceneObject);

#else // !BUILDING_SCENE_OBJECT_STATIC

	CORE_TOOLS_MUTEX_INIT(SceneObject);

#endif // BUILDING_SCENE_OBJECT_STATIC
