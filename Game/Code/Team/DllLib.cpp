// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 22:52)

#include "Team/TeamExport.h"

#include "Team/Team.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_TEAM_STATIC

	#include "DllLib.h"

#else // !BUILDING_TEAM_STATIC

	namespace Team
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_TEAM_STATIC
	
