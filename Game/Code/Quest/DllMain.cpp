///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:31)

#include "Quest/QuestExport.h"

#include "QuestFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_QUEST_STATIC

DLL_MAIN_FUNCTION(Quest);

#else  // !BUILDING_QUEST_STATIC

CORE_TOOLS_MUTEX_INIT(Quest);

#endif  // BUILDING_QUEST_STATIC
