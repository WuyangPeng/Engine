// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:08)

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
	class EllipseFit2
	{
	public:
		using ClassType = EllipseFit2<Real>;
		using Vector2D = Vector2D<Real>;
		using Points = std::vector<Vector2D>;
		using Matrix2 = Matrix2<Real>;
	 
	public:
		explicit EllipseFit2(const Points& points);

		CLASS_INVARIANT_DECLARE;

		Real GetExactly() const;

		const Vector2D GetCenter() const;
		const Matrix2 GetRotate() const;
		Real GetFirstExtent() const;
		Real GetSecondExtent() const;

		int GetNumPoint() const;
		const Vector2D GetPoint(int index) const;

	private:
		void Fit2();
		void InitialGuess();

		static Real Energy(const std::vector<Real>& input, const ClassType* userData);

	private:
		Points m_Points;
		Vector2D m_Center;
		Matrix2 m_Rotate;
		Real m_FirstExtent;
		Real m_SecondExtent;
		Real m_Exactly;
	};     

	using EllipseFit2f = EllipseFit2<float>;
	using EllipseFit2d = EllipseFit2<double>;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_H
