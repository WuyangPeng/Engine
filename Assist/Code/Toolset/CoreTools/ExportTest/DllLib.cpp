/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:22)

#ifndef BUILDING_STATIC

    #include "DllLib.h"

#else  // BUILDING_STATIC

namespace ExportTest
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_STATIC