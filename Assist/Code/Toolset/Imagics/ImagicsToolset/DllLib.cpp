///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:40)

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetExport.h"

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolset.h"

#ifndef BUILDING_IMAGICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_IMAGICS_STATIC

namespace ImagicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_IMAGICS_STATIC
