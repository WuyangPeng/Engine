///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:59)

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
