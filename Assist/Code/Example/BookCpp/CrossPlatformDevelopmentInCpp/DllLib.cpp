///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppExport.h"

#include "CrossPlatformDevelopmentInCpp.h"

#ifndef BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC

namespace CrossPlatformDevelopmentInCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC