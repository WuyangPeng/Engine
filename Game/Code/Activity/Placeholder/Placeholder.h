///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 17:12)

#ifndef ACTIVITY_PLACEHOLDER_PLACEHOLDER_H
#define ACTIVITY_PLACEHOLDER_PLACEHOLDER_H

#include "Activity/ActivityDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Activity
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
