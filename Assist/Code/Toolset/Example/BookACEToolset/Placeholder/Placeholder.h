///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/12 0:07)

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
