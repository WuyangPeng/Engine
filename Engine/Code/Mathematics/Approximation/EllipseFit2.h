///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:18)

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
    class EllipseFit2 final
    {
    public:
        using ClassType = EllipseFit2<Real>;

        using Vector2 = Vector2<Real>;
        using Points = std::vector<Vector2>;
        using Matrix2 = Matrix2<Real>;
        using Math = Math<Real>;

    public:
        explicit EllipseFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Matrix2 GetRotate() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;

        NODISCARD int GetNumPoint() const;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        using Container = std::vector<Real>;

    private:
        void Fit2();
        void InitialGuess();

        NODISCARD static Real Energy(const Container& input, const EllipseFit2* userData);

    private:
        Points points;
        Vector2 center;
        Matrix2 rotate;
        Real extent0;
        Real extent1;
        Real exactly;
    };

    using EllipseFit2F = EllipseFit2<float>;
    using EllipseFit2D = EllipseFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H
