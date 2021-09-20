// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:14)

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
	
