///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/22 22:03)

#include "Example/BookCpp/ThinkingInCppVolumeOne/ThinkingInCppVolumeOneExport.h"

#include "ThinkingInCppVolumeOne.h"

#ifndef BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

    #include "DllLib.h"

#else  // BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

namespace ThinkingInCppVolumeOne
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC
