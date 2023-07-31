///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:44)

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
