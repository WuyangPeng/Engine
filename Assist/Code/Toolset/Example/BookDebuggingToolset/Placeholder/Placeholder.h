///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 19:34)

#ifndef BOOK_DEBUGGING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_DEBUGGING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookDebuggingToolset/BookDebuggingToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookDebuggingToolset
{
    class BOOK_DEBUGGING_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_DEBUGGING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
