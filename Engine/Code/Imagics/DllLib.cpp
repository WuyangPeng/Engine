///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:59)

#include "Imagics/ImagicsExport.h"

#include "Imagics/Imagics.h"

#ifndef BUILDING_IMAGICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_IMAGICS_STATIC

namespace Imagics
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_IMAGICS_STATIC