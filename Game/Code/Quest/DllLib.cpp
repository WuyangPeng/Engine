///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:08)

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
