///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:03)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

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
