///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 10:29)

#ifndef RENDERING_BASE_TOTAL_ALLOCATION_H
#define RENDERING_BASE_TOTAL_ALLOCATION_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TotalAllocation
    {
    public:
        using ClassType = TotalAllocation;

    public:
        TotalAllocation() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumBytes() const noexcept;
        void AddNumBytes(int num) noexcept;
        NODISCARD int GetNumObjects() const noexcept;
        void AddNumObjects(int num) noexcept;

    private:
        int numBytes;
        int numObjects;
    };
}

#endif  // RENDERING_BASE_TOTAL_ALLOCATION_H
