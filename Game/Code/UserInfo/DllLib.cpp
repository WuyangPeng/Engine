///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:56)

#include "UserInfo/UserInfoExport.h"

#include "UserInfo/UserInfo.h"

#ifndef BUILDING_USER_INFO_STATIC

    #include "DllLib.h"

#else  // !BUILDING_USER_INFO_STATIC

namespace UserInfo
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_USER_INFO_STATIC
