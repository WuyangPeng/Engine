/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#ifndef CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "ChatServer/ChatServerCore/ChatServerCoreDll.h"

#include "ChatServer/ChatServerCore/Helper/ExportMacro.h"

namespace ChatServerCore
{
    class CHAT_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H