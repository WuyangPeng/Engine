///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 16:04)

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
