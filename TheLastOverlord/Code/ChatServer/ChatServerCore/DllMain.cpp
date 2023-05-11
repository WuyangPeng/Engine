///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 20:55)

#include "ChatServerCoreExport.h"

#include "ChatServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHAT_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(ChatServerCore);

#else  // !BUILDING_CHAT_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(ChatServerCore);

#endif  // BUILDING_CHAT_SERVER_CORE_STATIC