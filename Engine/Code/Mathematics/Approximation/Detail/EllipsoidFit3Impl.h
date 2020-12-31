///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 10:55)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H

#include "Mathematics/MathematicsDll.h"

// ��һ����ʽ����Բ��ΪX^t A X + B^t X + C = 0 ��
// ����A������3x3����B��һ��3x1ʸ����C��һ����������X��һ��3x1������
// ���ƽ����(X-U)^t A (X-U) = U^t A U - C������U = -0.5 A^{-1} B��
// ����M = A/(U^t A U - C)��
// ��Բ����(X-U)^t M (X-U) = 1��
// ����M = Real^t D�趨Real������Real��������D�ǶԽ���ʹ�����Խ��
// ����ʽ�ֽ����ʽ��Բ����(X-U)^t Real^t D^t Real (X-U) = 1��

// �ҵ���С������ϵ�һ���P[0]��P[N-1]��
// ���󷵻�ֵ����(U,Real,D)����С��������������
// EllipseFit3<Real> fit(points);
// Real exactly = fit.GetExactly();

#include "Mathematics/Algebra/Matrix3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE EllipsoidFit3Impl final
    {
    public:
        using ClassType = EllipsoidFit3Impl;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Matrix3 = Matrix3<Real>;
        using Angle = std::vector<Real>;
        using Math = Math<Real>;

    public:
        explicit EllipsoidFit3Impl(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetExactly() const noexcept;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Matrix3 GetRotate() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;

        [[nodiscard]] int GetNumPoint() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Fit3();
        void InitialGuess();

        static Real Energy(const Angle& input, const EllipsoidFit3Impl* userData);

        static const Angle MatrixToAngles(const Matrix3& rotate);
        static const Matrix3 AnglesToMatrix(const Angle& angle) noexcept;

    private:
        Points m_Points;
        Vector3D m_Center;
        Matrix3 m_Rotate;
        Real m_Extent0;
        Real m_Extent1;
        Real m_Extent2;
        Real m_Exactly;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_IMPL_H
