///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/23 22:41)

#ifndef BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookWindowsAPIToolset/BookWindowsAPIToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookWindowsAPIToolset
{
    class BOOK_WINDOWS_API_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_WINDOWS_API_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
