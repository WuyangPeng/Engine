///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 16:54)

#ifndef MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H
#define MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // һ������С������������档
    // ���������ʽz = c0*x^2+c1*x*y+c2*y^2+c3*x+c4*y+c5��
    // һ���ɹ�������ǡ�m_IsFitSuccess��Ϊtrue��
    // ����һ����Ʒ(x_i,y_i,z_i) Ϊ0 <= i < N,�����Ҽٶ���ֵλ��һ��������
    //     z = p0*x*x + p1*x*y + p2*y*y + p3*x + p4*y + p5  = Dot(P,Q(x,y))
    // ���� P = (p0,p1,p2,p3,p4,p5) �� Q(x,y) = (x*x,x*y,y*y,x,y,1),
    // ѡ��P����С��ƽ�����ĺ�
    //     E(P) = sum_{i=0}^{N-1} [Dot(P,Q_i)-z_i]^2
    // ���� Q_i = Q(x_i,y_i).
    // ��Сֵ��E�Ľ�����������ʱ������
    //     grad(E) = 2 sum_{i=0}^{N-1} [Dot(P,Q_i)-z_i] Q_i = 0
    // ��Щ����ת����6�����̵�6��δ֪��ϵͳ
    //     [(sum_{i=0}^{N-1} Q_i Q_i^t] P = sum_{i=0}^{N-1} z_i Q_i
    // �ò�ƷQ_i��6x1����Q_i��1x6��Q_i^t�������һ��6��6����ĳ˻���
    // ����6x6�Գƾ���A = sum_{i=0}^{N-1} Q_i Q_i^t��6x1����B = sum_{i=0}^{N-1} z_i Q_i
    // P��ѡ���ǽ�����ϵͳA*P = B�ķ��̡�
    // A��B����Ŀ��ʾ�ڱ�����Ӧ�Ĳ�Ʒ�ܺ͡� ���磬
    // s(x^3 y) = sum_{i=0}^{N-1} x_i^3 y_i.
    //
    // +-                                                     -++  +   +-      -+
    // | s(x^4) s(x^3 y)   s(x^2 y^2) s(x^3)   s(x^2 y) s(x^2) ||p0|   |s(z x^2)|
    // |        s(x^2 y^2) s(x y^3)   s(x^2 y) s(x y^2) s(x y) ||p1|   |s(z x y)|
    // |                   s(y^4)     s(x y^2) s(y^3)   s(y^2) ||p2| = |s(z y^2)|
    // |                              s(x^2)   s(x y)   s(x)   ||p3|   |s(z x)  |
    // |                                       s(y^2)   s(y)   ||p4|   |s(z y)  |
    // |                                                s(1)   ||p5|   |s(z)    |
    // +-                                                     -++  +   +-      -+
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE ParaboloidFit3 final
    {
    public:
        using ClassType = ParaboloidFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit ParaboloidFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] VariableLengthVector GetCoeff() const;
        [[nodiscard]] bool GetIsFitSuccess() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static int sm_VariableMatrixSize = 6;

    private:
        VariableLengthVector m_Coeff;
        bool m_IsFitSuccess;
    };

    using FloatParaboloidFit3 = ParaboloidFit3<float>;
    using DoubleParaboloidFit3 = ParaboloidFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H
