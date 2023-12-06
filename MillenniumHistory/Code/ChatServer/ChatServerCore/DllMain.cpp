/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "ChatServerCoreExport.h"

#include "ChatServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHAT_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(ChatServerCore);

#else  // !BUILDING_CHAT_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(ChatServerCore);

#endif  // BUILDING_CHAT_SERVER_CORE_STATIC