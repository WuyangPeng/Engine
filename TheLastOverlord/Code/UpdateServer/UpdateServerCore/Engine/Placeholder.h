///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 23:31)

#ifndef UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "UpdateServer/UpdateServerCore/UpdateServerCoreDll.h"

#include "UpdateServer/UpdateServerCore/Macro/ExportMacro.h"

namespace UpdateServerCore
{
    class UPDATE_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
