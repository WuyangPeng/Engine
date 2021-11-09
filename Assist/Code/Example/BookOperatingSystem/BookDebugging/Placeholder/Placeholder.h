///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 21:35)

#ifndef BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BookDebugging/BookDebuggingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookDebugging
{
    class BOOK_DEBUGGING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_DEBUGGING_PLACEHOLDER_PLACEHOLDER_H
