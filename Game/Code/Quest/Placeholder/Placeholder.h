///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:08)

#ifndef QUEST_PLACEHOLDER_PLACEHOLDER_H
#define QUEST_PLACEHOLDER_PLACEHOLDER_H

#include "Quest/QuestDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Quest
{
    class QUEST_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // QUEST_PLACEHOLDER_PLACEHOLDER_H
