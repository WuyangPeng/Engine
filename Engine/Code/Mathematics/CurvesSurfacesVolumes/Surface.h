///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 10:47)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Surface
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Surface<Real>;

    public:
        virtual ~Surface() noexcept = default;

        Surface(const Surface& rhs) noexcept = default;
        Surface& operator=(const Surface& rhs) noexcept = default;
        Surface(Surface&& rhs) noexcept = default;
        Surface& operator=(Surface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        Surface() noexcept = default;
    };

    using SurfaceF = Surface<float>;
    using SurfaceD = Surface<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H
