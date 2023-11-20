/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

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