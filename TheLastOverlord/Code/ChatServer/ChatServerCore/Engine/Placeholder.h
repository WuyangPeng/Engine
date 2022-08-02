///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 21:00)

#ifndef CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "ChatServer/ChatServerCore/ChatServerCoreDll.h"

#include "ChatServer/ChatServerCore/Macro/ExportMacro.h"

namespace ChatServerCore
{
    class CHAT_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CHAT_SERVER_CORE_ENGINE_PLACEHOLDER_H