// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 20:42)

#include "Arena/ArenaExport.h"

#include "Arena/Arena.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_ARENA_STATIC

	#include "DllLib.h"

#else // !BUILDING_ARENA_STATIC

	namespace Arena
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ARENA_STATIC
	
