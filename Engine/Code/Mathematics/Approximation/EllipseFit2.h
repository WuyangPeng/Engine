///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/02 19:03)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H

#include "Mathematics/MathematicsDll.h"

// һ����ʽ����ԲΪX^t A X + B^t X + C = 0������A������2 x 2����B��2 x 1������C��һ��������
// ��X��һ��2��1������
// ���������(X-U)^t A (X-U) = U^t A U - C������U = -0.5 A^{-1} B��
// ����M = A/(U^t A U - C)��
// ��Բ��(X-U)^t M (X-U) = 1��
// ����M = Real^t D Real������Real��������D�ǶԽ�����ʹ�����Խǵ��
// ��Բ��ʽ�ֽ����ʽ��(X-U)^t Real^t D^t Real (X-U) = 1��

// �ҵ���С����������N�ĵ�P[0]��P[N-1]������ֵ���� (U,Real,D)����С��������������

#include "Mathematics/Algebra/Matrix2.h"

namespace Mathematics
{
    template <typename Real>
    class EllipseFit2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EllipseFit2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE EllipseFit2 final
    {
    public:
        using EllipseFit2Impl = EllipseFit2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(EllipseFit2);

        using Vector2D = Vector2D<Real>;
        using Points = std::vector<Vector2D>;
        using Matrix2 = Matrix2<Real>;

    public:
        explicit EllipseFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetExactly() const noexcept;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Matrix2 GetRotate() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;

        [[nodiscard]] int GetNumPoint() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        IMPL_TYPE_DECLARE(EllipseFit2);
    };

    using FloatEllipseFit2 = EllipseFit2<float>;
    using DoubleEllipseFit2 = EllipseFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H
