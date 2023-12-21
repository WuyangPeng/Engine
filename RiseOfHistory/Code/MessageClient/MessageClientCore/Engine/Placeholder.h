/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "MessageClient/MessageClientCore/MessageClientCoreDll.h"

#include "MessageClient/MessageClientCore/Helper/ExportMacro.h"

namespace MessageClientCore
{
    class MESSAGE_CLIENT_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H