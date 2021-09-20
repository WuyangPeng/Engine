// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 22:00)

#include "Quest/QuestExport.h"

#include "Quest/Quest.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_QUEST_STATIC

	#include "DllLib.h"

#else // !BUILDING_QUEST_STATIC

	namespace Quest
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_QUEST_STATIC
	
