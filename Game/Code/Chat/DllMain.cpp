///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:59)

#include "Chat/ChatExport.h"

#include "ChatFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHAT_STATIC

DLL_MAIN_FUNCTION(Chat);

#else  // !BUILDING_CHAT_STATIC

CORE_TOOLS_MUTEX_INIT(Chat);

#endif  // BUILDING_CHAT_STATIC
