///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:08)

#include "Quest/QuestExport.h"

#include "QuestFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_QUEST_STATIC

DLL_MAIN_FUNCTION(Quest);

#else  // !BUILDING_QUEST_STATIC

CORE_TOOLS_MUTEX_INIT(Quest);

#endif  // BUILDING_QUEST_STATIC
