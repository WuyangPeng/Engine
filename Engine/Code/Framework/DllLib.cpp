///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 13:58)

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h"

#ifndef BUILDING_FRAMEWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_FRAMEWORK_STATIC

namespace Framework
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_FRAMEWORK_STATIC