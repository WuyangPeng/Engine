///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 15:20)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H

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

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Matrix3.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class EllipsoidFit3 final
    {
    public:
        using ClassType = EllipsoidFit3<Real>;

        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Matrix3 = Matrix3<Real>;
        using Angle = std::vector<Real>;
        using Math = Math<Real>;

    public:
        explicit EllipsoidFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Matrix3 GetRotate() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetExtent2() const noexcept;

        NODISCARD int GetNumPoint() const;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Fit3();
        void InitialGuess();

        static Real Energy(const Angle& input, const EllipsoidFit3* userData);

        static Angle MatrixToAngles(const Matrix3& rotate);
        static Matrix3 AnglesToMatrix(const Angle& angle) noexcept;

    private:
        Points points;
        Vector3 center;
        Matrix3 rotate;
        Real extent0;
        Real extent1;
        Real extent2;
        Real exactly;
    };

    using EllipsoidFit3F = EllipsoidFit3<float>;
    using EllipsoidFit3D = EllipsoidFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H
