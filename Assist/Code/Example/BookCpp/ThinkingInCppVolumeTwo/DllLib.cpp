///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/23 20:49)

#include "Example/BookCpp/ThinkingInCppVolumeTwo/ThinkingInCppVolumeTwoExport.h"

#include "ThinkingInCppVolumeTwo.h"

#ifndef BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

    #include "DllLib.h"

#else  // BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

namespace ThinkingInCppVolumeTwo
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC
