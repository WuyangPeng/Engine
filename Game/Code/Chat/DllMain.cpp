///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:31)

#include "Chat/ChatExport.h"

#include "ChatFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHAT_STATIC

DLL_MAIN_FUNCTION(Chat);

#else  // !BUILDING_CHAT_STATIC

CORE_TOOLS_MUTEX_INIT(Chat);

#endif  // BUILDING_CHAT_STATIC
