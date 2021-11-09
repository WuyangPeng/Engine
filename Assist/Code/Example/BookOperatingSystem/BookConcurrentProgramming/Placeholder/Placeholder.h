///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/26 23:05)

#ifndef BOOK_CONCURRENT_PROGRAMMING_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_CONCURRENT_PROGRAMMING_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BookConcurrentProgramming/BookConcurrentProgrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookConcurrentProgramming
{
    class BOOK_CONCURRENT_PROGRAMMING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_PLACEHOLDER_PLACEHOLDER_H
