// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:28)

#include "MessageClientCoreExport.h"

#include "MessageClientCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MESSAGE_CLIENT_CORE_STATIC

	DLL_MAIN_FUNCTION(MessageClientCore);

#else // !BUILDING_MESSAGE_CLIENT_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(MessageClientCore);

#endif // BUILDING_MESSAGE_CLIENT_CORE_STATIC
