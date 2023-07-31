///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:56)

#include "UserInfo/UserInfoExport.h"

#include "UserInfoFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INFO_STATIC

DLL_MAIN_FUNCTION(UserInfo);

#else  // !BUILDING_USER_INFO_STATIC

CORE_TOOLS_MUTEX_INIT(UserInfo);

#endif  // BUILDING_USER_INFO_STATIC
