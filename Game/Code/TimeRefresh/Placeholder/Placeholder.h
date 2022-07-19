///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 14:42)

#ifndef ACTIVITY_PLACEHOLDER_PLACEHOLDER_H
#define ACTIVITY_PLACEHOLDER_PLACEHOLDER_H

#include "TimeRefresh/TimeRefreshDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace TimeRefresh
{
    class ACTIVITY_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ACTIVITY_PLACEHOLDER_PLACEHOLDER_H
