///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/12 0:07)

#ifndef BOOK_ACE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_ACE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookACEToolset/BookACEToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookACEToolset
{
    class BOOK_ACE_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_ACE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
