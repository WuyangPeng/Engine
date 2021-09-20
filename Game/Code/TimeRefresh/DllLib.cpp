// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 21:38)

#include "Activity/ActivityExport.h"

#include "Activity/Activity.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_ACTIVITY_STATIC

	#include "DllLib.h"

#else // !BUILDING_ACTIVITY_STATIC

	namespace Activity
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ACTIVITY_STATIC
	
