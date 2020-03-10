// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:29)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterfaceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

	DLL_MAIN_FUNCTION(UserInterface);

#else // !BUILDING_USER_INTERFACE_STATIC

	CORE_TOOLS_MUTEX_INIT(UserInterface);

#endif // !BUILDING_USER_INTERFACE_STATIC