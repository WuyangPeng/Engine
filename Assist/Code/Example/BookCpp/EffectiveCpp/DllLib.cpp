///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:45)

#include "Example/BookCpp/EffectiveCpp/EffectiveCppExport.h"

#include "EffectiveCpp.h"

#ifndef BUILDING_EFFECTIVE_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_EFFECTIVE_CPP_STATIC

namespace EffectiveCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EFFECTIVE_CPP_STATIC
