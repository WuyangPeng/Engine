///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 18:00)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    // �������Ϊ
    // 0 = C[0] + C[1]*X + C[2]*Y + C[3]*X^2 + C[4]*Y^2 + C[5]*X*Y,
    // ����Length(C) = 1��
    // ��С��E(C) = C^t M C�� Length(C) = 1 ��
    // M = (sum_i V_i)(sum_i V_i)^t
    // ����  V = (1, X, Y, X^2, Y^2, X*Y)
    //
    // ��СֵΪM����С����ֵ��C��һ����Ӧ�ĵ�λ���ȵ�����������
    //
    // ����:
    //   Ҫ��ϵ�����顣
    //
    // ���:
    //   coeff = �������ϵ����������������
    //   eigenValue = �ǷǸ�ֵ�����Ҳ�������ϵĹ淶��ʽ
    //  ����С����ֵ;0 = ��ȷ��ϣ�����Ϊ������

    // ���η��̿��Ա��ֽ�ΪP^T A P + B^T P + K = 0��
    // ����P = (X,Y,Z), K = C[0], B = (C[1],C[2],C[3]),
    // �Լ�A��3��3�Գƾ���A00 = C[4], A11 = C[5],
    // A22 = C[6]��A01 = C[7]/2, A02 = C[8]/2, �� A12 = C[9]/2��
    // ����A = Real^T D Real������Real�����������D�ǶԽǾ���ʹ�������ֽ⣩��
    // ���壺V = Real P = (v0,v1,v2), E = Real B = (e0,e1,e2),
    // D = diag(d0,d1,d2),��f = K
    // �Ի��d0 v0^2 + d1 v1^2 + d2 v^2 + e0 v0 + e1 v1 + e2 v2 + f = 0
    // ����ֵ������d_i�ķ��š�

    template <typename Real>
    class QuadraticFit2 final
    {
    public:
        using ClassType = QuadraticFit2<Real>;
        using Vector2 = Vector2<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using Points = std::vector<Vector2>;
        using Math = Math<Real>;

    public:
        explicit QuadraticFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableLengthVector GetCoeff() const;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static int eigenSystemSize = 6;

    private:
        VariableLengthVector coeff;
        Real eigenValue;
    };

    using QuadraticFit2F = QuadraticFit2<float>;
    using QuadraticFit2D = QuadraticFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H
