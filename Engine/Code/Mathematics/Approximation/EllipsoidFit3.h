// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:28)

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

#include "Mathematics/Algebra/Matrix3.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class EllipsoidFit3
	{
	public:
		using ClassType = EllipsoidFit3;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;
		using Matrix3 = Matrix3<Real>;
		using Angle = std::vector<Real>;

	public:
		explicit EllipsoidFit3(const Points& points);

		CLASS_INVARIANT_DECLARE;

		Real GetExactly() const;

		const Vector3D GetCenter() const;
		const Matrix3 GetRotate() const;
		Real GetFirstExtent() const;
		Real GetSecondExtent() const;
		Real GetThirdExtent() const;

		int GetNumPoint() const;
		const Vector3D GetPoint(int index) const;

	private:
		void Fit3();
		void InitialGuess();

		static Real Energy(const std::vector<Real>& input, const ClassType* userData);

		static const Angle MatrixToAngles(const Matrix3& rotate);
		static const Matrix3 AnglesToMatrix(const Angle& angle);

	private:
		Points m_Points;
		Vector3D m_Center;
		Matrix3 m_Rotate;
		Real m_FirstExtent;
		Real m_SecondExtent;
		Real m_ThirdExtent;
		Real m_Exactly;
	};

	using EllipsoidFit3f = EllipsoidFit3<float>;
	using EllipsoidFit3d = EllipsoidFit3<double>;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_H	
