///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/23 22:18)

#ifndef BOOK_EXPERIENCE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_EXPERIENCE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookExperienceToolset/BookExperienceToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperienceToolset
{
    class BOOK_EXPERIENCE_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_EXPERIENCE_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
