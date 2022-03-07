///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/28 16:06)

#ifndef MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
#define MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    // ʹ�ÿ��ٽ����㷨��Ǳ���������ǵ��ñ�׼����ѧ�⺯����
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric final
    {
    public:
        static_assert(std::is_floating_point_v<Real>, "Real must be floating point.");

        using ClassType = FastTrigonometric<Real>;
        using Math = Math<Real>;

    public:
        // ���ö���ʽ�ƽ����Ǻ����ͷ����Ǻ����Ŀ��ټ��㡣�ٶ����������������

        // ��������ڷ�Χ[0,pi/2]

        // 1.0e-3����
        NODISCARD static Real FastSinRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-8���ȣ�double��
        NODISCARD static Real FastSinPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastSinMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ڷ�Χ[0,pi/2]

        // 1.0e-2����
        NODISCARD static Real FastCosRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-8���ȣ�double��
        NODISCARD static Real FastCosPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastCosMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ڷ�Χ[0,pi/4]

        // 1.0e-3����
        NODISCARD static Real FastTanRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7����
        NODISCARD static Real FastTanPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastTanMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ڷ�Χ[0,1]

        // 1.0e-4����
        NODISCARD static Real FastInvSinRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
        NODISCARD static Real FastInvSinPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ڷ�Χ [0,1]

        // 1.0e-4����
        NODISCARD static Real FastInvCosRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
        NODISCARD static Real FastInvCosPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ڷ�Χ [-1,1]

        // 1.0e-4����
        NODISCARD static Real FastInvTanRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7����
        NODISCARD static Real FastInvTanPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };

    using FastTrigonometricF = FastTrigonometric<float>;
    using FastTrigonometricD = FastTrigonometric<double>;
}

#endif  // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
