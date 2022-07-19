///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 14:05)

#include "UserInfo/UserInfoExport.h"

#include "UserInfoFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INFO_STATIC

DLL_MAIN_FUNCTION(UserInfo);

#else  // !BUILDING_USER_INFO_STATIC

CORE_TOOLS_MUTEX_INIT(UserInfo);

#endif  // BUILDING_USER_INFO_STATIC
