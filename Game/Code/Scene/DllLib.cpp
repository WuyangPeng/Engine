// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:14)

#include "Scene/SceneExport.h"

#include "Scene/Scene.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SCENE_STATIC

	#include "DllLib.h"

#else // !BUILDING_SCENE_STATIC

	namespace Scene
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCENE_STATIC
	
