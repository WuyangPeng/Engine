///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:08)

#include "Quest/QuestExport.h"

#include "Quest/Quest.h"

#ifndef BUILDING_QUEST_STATIC

    #include "DllLib.h"

#else  // !BUILDING_QUEST_STATIC

namespace Quest
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_QUEST_STATIC
