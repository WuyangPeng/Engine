/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LoginServer/LoginServerCore/LoginServerCoreDll.h"

#include "LoginServer/LoginServerCore/Helper/ExportMacro.h"

namespace LoginServerCore
{
    class LOGIN_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H