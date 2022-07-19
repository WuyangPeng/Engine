///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 11:23)

#ifndef ARENA_PLACEHOLDER_PLACEHOLDER_H
#define ARENA_PLACEHOLDER_PLACEHOLDER_H

#include "Arena/ArenaDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Arena
{
    class ARENA_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ARENA_PLACEHOLDER_PLACEHOLDER_H
