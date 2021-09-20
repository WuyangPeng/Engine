// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 22:00)

#include "Quest/QuestExport.h"

#include "QuestFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_QUEST_STATIC

	DLL_MAIN_FUNCTION(Quest);

#else // !BUILDING_QUEST_STATIC

	CORE_TOOLS_MUTEX_INIT(Quest);

#endif // BUILDING_QUEST_STATIC
