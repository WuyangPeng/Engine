///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 13:20)

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
