// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:21)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

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
	//   m_Coeff = �������ϵ����������������
	//   m_EigenValue = �ǷǸ�ֵ�����Ҳ�������ϵĹ淶��ʽ
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
    class QuadraticFit3
    {
    public:
		using ClassType = QuadraticFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
        
    public:
		explicit QuadraticFit3(const std::vector<Vector3D>& points);

        CLASS_INVARIANT_DECLARE;
        
		const VariableLengthVector GetCoeff() const;
        Real GetEigenValue() const;
        
    private:
        void Calculate(const std::vector<Vector3D>& points);
        
    private:
		constexpr static auto sm_EigenSystemSize = 10;

	private:
		VariableLengthVector m_Coeff;
        Real m_EigenValue;
    };

	using QuadraticFit3d = QuadraticFit3<double>;
	using QuadraticFit3f = QuadraticFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
