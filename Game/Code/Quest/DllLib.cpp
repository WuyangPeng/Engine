///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 16:04)

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
