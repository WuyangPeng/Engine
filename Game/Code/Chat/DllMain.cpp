// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/06 20:17)

#include "Chat/ChatExport.h"

#include "ChatFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_CHAT_STATIC

	DLL_MAIN_FUNCTION(Chat);

#else // !BUILDING_CHAT_STATIC

	CORE_TOOLS_MUTEX_INIT(Chat);

#endif // BUILDING_CHAT_STATIC
