///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:31)

#include "Chat/ChatExport.h"

#include "Chat/Chat.h"

#ifndef BUILDING_CHAT_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CHAT_STATIC

namespace Chat
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CHAT_STATIC
