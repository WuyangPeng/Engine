///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/21 19:17)

#ifndef BOOK_BOOST_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_BOOST_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/BookBoost/BookBoostDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookBoost
{
    class BOOK_BOOST_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_BOOST_PLACEHOLDER_PLACEHOLDER_H
