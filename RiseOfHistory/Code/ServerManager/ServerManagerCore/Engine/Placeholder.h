/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 09:55)

#ifndef SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H
#define SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H

#include "ServerManager/ServerManagerCore/ServerManagerCoreDll.h"

#include "ServerManager/ServerManagerCore/Helper/ExportMacro.h"

namespace ServerManagerCore
{
    class SERVER_MANAGER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H