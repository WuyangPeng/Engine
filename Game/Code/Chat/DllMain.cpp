///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 10:24)

#include "Chat/ChatExport.h"

#include "ChatFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHAT_STATIC

DLL_MAIN_FUNCTION(Chat);

#else  // !BUILDING_CHAT_STATIC

CORE_TOOLS_MUTEX_INIT(Chat);

#endif  // BUILDING_CHAT_STATIC
