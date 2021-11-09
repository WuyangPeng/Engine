///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/02 22:36)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_CONCURRENT_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookConcurrentProgrammingToolset/BookConcurrentProgrammingToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookConcurrentProgrammingToolset
{
    class BOOK_CONCURRENT_PROGRAMMING_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
