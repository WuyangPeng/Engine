/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "UpdateServer/UpdateServerCore/UpdateServerCoreDll.h"

#include "UpdateServer/UpdateServerCore/Helper/ExportMacro.h"

namespace UpdateServerCore
{
    class UPDATE_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H