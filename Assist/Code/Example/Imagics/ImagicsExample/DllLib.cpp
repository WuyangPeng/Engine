///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:41)

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
