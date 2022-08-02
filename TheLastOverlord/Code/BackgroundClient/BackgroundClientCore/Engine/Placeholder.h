///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 22:52)

#ifndef BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "BackgroundClient/BackgroundClientCore/BackgroundClientCoreDll.h"

#include "BackgroundClient/BackgroundClientCore/Macro/ExportMacro.h"

namespace BackgroundClientCore
{
    class BACKGROUND_CLIENT_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H
