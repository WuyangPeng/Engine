// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/03 21:50)

#include "SceneObject/SceneObjectExport.h"

#include "SceneObject/SceneObject.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SCENE_OBJECT_STATIC

	#include "DllLib.h"

#else // !BUILDING_SCENE_OBJECT_STATIC

	namespace SceneObject
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCENE_OBJECT_STATIC
	
