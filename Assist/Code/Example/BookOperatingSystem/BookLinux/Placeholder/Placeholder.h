///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 14:32)

#ifndef BOOK_LINUX_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_LINUX_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BookLinux/BookLinuxDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookLinux
{
    class BOOK_LINUX_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_LINUX_PLACEHOLDER_PLACEHOLDER_H