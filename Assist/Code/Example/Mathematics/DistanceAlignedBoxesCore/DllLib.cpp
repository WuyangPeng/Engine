///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/20 11:01)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCore.h"

#ifndef BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

namespace DistanceAlignedBoxesCore
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC
