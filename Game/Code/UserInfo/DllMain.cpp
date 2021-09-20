// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/03 21:50)

#include "UserInfo/UserInfoExport.h"

#include "UserInfoFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_USER_INFO_STATIC

	DLL_MAIN_FUNCTION(UserInfo);

#else // !BUILDING_USER_INFO_STATIC

	CORE_TOOLS_MUTEX_INIT(UserInfo);

#endif // BUILDING_USER_INFO_STATIC
