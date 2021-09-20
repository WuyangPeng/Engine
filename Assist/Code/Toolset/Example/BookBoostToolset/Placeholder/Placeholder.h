///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 20:46)

#ifndef BOOK_BOOST_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_BOOST_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookBoostToolset/BookBoostToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookBoostToolset
{
    class BOOK_BOOST_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_BOOST_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
