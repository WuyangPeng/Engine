///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 14:54)

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
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric final
    {
    public:
        using ClassType = FastTrigonometric<Real>;
        using Math = Math<Real>;

    public:
        // ���ö���ʽ�ƽ����Ǻ����ͷ����Ǻ����Ŀ��ټ��㡣�ٶ����������������

        // ��������ڷ�Χ[0,pi/2]

        // 1.0e-3����
        NODISCARD static Real FastSinRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-8���ȣ�double��
        NODISCARD static Real FastSinPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastSinMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��������ڷ�Χ[0,pi/2]

        // 1.0e-2����
        NODISCARD static Real FastCosRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-8���ȣ�double��
        NODISCARD static Real FastCosPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastCosMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��������ڷ�Χ[0,pi/4]

        // 1.0e-3����
        NODISCARD static Real FastTanRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7����
        NODISCARD static Real FastTanPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
        NODISCARD static Real FastTanMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��������ڷ�Χ[0,1]

        // 1.0e-4����
        NODISCARD static Real FastInvSinRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
        NODISCARD static Real FastInvSinPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��������ڷ�Χ [0,1]

        // 1.0e-4����
        NODISCARD static Real FastInvCosRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
        NODISCARD static Real FastInvCosPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ��������ڷ�Χ [-1,1]

        // 1.0e-4����
        NODISCARD static Real FastInvTanRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7����
        NODISCARD static Real FastInvTanPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using FastTrigonometricF = FastTrigonometric<float>;
    using FastTrigonometricD = FastTrigonometric<double>;
}

#endif  // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
