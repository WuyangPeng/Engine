///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 10:25)

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
