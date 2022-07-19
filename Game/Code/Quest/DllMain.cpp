///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 16:03)

#include "Quest/QuestExport.h"

#include "QuestFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_QUEST_STATIC

DLL_MAIN_FUNCTION(Quest);

#else  // !BUILDING_QUEST_STATIC

CORE_TOOLS_MUTEX_INIT(Quest);

#endif  // BUILDING_QUEST_STATIC
