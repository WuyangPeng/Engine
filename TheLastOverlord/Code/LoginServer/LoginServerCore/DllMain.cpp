// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:02)

#include "LoginServerCoreExport.h"

#include "LoginServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOGIN_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(LoginServerCore);

#else // !BUILDING_LOGIN_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(LoginServerCore);

#endif // BUILDING_LOGIN_SERVER_CORE_STATIC
