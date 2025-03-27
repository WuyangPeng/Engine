///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:28)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    // �������Ϊ
    //   0 = C[0] + C[1]*X + C[2]*Y + C[3]*Z + C[4]*X^2 + C[5]*Y^2 +
    //       C[6]*Z^2 + C[7]*X*Y + C[8]*X*Z + C[9]*Y*Z
    // ����Length(C) = 1��
    // ��С��E(C) = C^t M C�� Length(C) = 1 ��
    // M = (sum_i V_i)(sum_i V_i)^t ����
    // V = (1, X, Y, Z, X^2, Y^2, Z^2, X*Y, X*Z, Y*Z)

    // ��СֵΪM����С����ֵ��C��һ����Ӧ�ĵ�λ���ȵ�����������

    // ����:
    //   n = Ҫ��ϵ��������
    //   p[0..n-1] = Ҫ��ϵ�����顣
    //
    // ���:
    //   coeff = �������ϵ����������������
    //   eigenValue = �ǷǸ�ֵ�����Ҳ�������ϵĹ淶��ʽ
    //  ����С����ֵ;0 = ��ȷ��ϣ�����Ϊ������

    // �淶��ʽ��  ���η��̿��Ա��ֽ�Ϊ
    // P^T A P + B^T P + K = 0 ���� P = (X,Y,Z), K = C[0], B = (C[1],C[2],C[3]),
    // �Լ�A��3��3�Գƾ��� A00 = C[4], A11 = C[5], A22 = C[6],
    // A01 = C[7]/2, A02 = C[8]/2, �� A12 = C[9]/2.
    // ���� A = Real^T D Real����Real�����������D�ǶԽǾ���ʹ�������ֽ⣩��
    // ���� V = Real P = (v0,v1,v2), E = Real B = (e0,e1,e2), D = diag(d0,d1,d2), �� f = K
    // �Ի��
    //   d0 v0^2 + d1 v1^2 + d2 v^2 + e0 v0 + e1 v1 + e2 v2 + f = 0
    // ����ֵ������d_i�ķ��š�

    template <typename Real>
    class QuadraticFit3 final
    {
    public:
        using ClassType = QuadraticFit3<Real>;

        using Vector3Type = Vector3<Real>;
        using VariableLengthVectorType = VariableLengthVector<Real>;
        using Points = std::vector<Vector3Type>;

    public:
        explicit QuadraticFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableLengthVectorType GetCoeff() const;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static auto eigenSystemSize = 10;

    private:
        VariableLengthVectorType coeff;
        Real eigenValue;
    };

    using QuadraticFit3F = QuadraticFit3<float>;
    using QuadraticFit3D = QuadraticFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
