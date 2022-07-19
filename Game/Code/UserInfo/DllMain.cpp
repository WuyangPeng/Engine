///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/14 14:05)

#include "UserInfo/UserInfoExport.h"

#include "UserInfoFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INFO_STATIC

DLL_MAIN_FUNCTION(UserInfo);

#else  // !BUILDING_USER_INFO_STATIC

CORE_TOOLS_MUTEX_INIT(UserInfo);

#endif  // BUILDING_USER_INFO_STATIC
