///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/ThinkingLowLevelWritingHighLevel/ThinkingLowLevelWritingHighLevelExport.h"

#include "ThinkingLowLevelWritingHighLevel.h"

#ifndef BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC

    #include "DllLib.h"

#else  // BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC

namespace ThinkingLowLevelWritingHighLevel
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC
