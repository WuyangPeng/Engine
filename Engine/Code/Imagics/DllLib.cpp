/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:34)

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