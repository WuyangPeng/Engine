// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 20:17)

#include "Chat/ChatExport.h"

#include "ChatFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_CHAT_STATIC

	DLL_MAIN_FUNCTION(Chat);

#else // !BUILDING_CHAT_STATIC

	CORE_TOOLS_MUTEX_INIT(Chat);

#endif // BUILDING_CHAT_STATIC
