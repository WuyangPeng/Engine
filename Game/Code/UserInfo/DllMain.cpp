// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/03 21:50)

#include "UserInfo/UserInfoExport.h"

#include "UserInfoFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_USER_INFO_STATIC

	DLL_MAIN_FUNCTION(UserInfo);

#else // !BUILDING_USER_INFO_STATIC

	CORE_TOOLS_MUTEX_INIT(UserInfo);

#endif // BUILDING_USER_INFO_STATIC
