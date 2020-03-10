// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:21)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

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
    //   m_Coeff = �������ϵ����������������
    //   m_EigenValue = �ǷǸ�ֵ�����Ҳ�������ϵĹ淶��ʽ
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
    class QuadraticFit2
    {
    public:
        using ClassType = QuadraticFit2<Real>;
        using Vector2D = Vector2D<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
        
    public:
        explicit QuadraticFit2(const std::vector<Vector2D>& points);

        CLASS_INVARIANT_DECLARE;
        
		const VariableLengthVector GetCoeff() const;
        Real GetEigenValue() const;
        
    private:
        void Calculate(const std::vector<Vector2D>& points);
        
    private:
		const static int sm_EigenSystemSize = 6;

	private:
		VariableLengthVector m_Coeff;
        Real m_EigenValue;
    };

	using QuadraticFit2d = QuadraticFit2<double>;
	using QuadraticFit2f = QuadraticFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_H
