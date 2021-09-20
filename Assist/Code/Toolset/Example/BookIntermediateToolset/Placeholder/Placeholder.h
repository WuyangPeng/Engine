///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/24 16:26)

#ifndef BOOK_INTERMEDIATE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_INTERMEDIATE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookIntermediateToolset/BookIntermediateToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookIntermediateToolset
{
    class BOOK_INTERMEDIATE_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_INTERMEDIATE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
