// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 22:00)

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
	
