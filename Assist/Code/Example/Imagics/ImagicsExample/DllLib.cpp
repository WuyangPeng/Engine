///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 17:07)

#include "Example/Imagics/ImagicsExample/ImagicsExampleExport.h"

#include "Example/Imagics/ImagicsExample/ImagicsExample.h"

#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_IMAGICS_EXAMPLE_STATIC

namespace ImagicsExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_IMAGICS_EXAMPLE_STATIC
