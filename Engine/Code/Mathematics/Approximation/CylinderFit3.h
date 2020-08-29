// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:27)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H

#include "Mathematics/MathematicsDll.h"

// ��С�����������(x,y,z)��һ������Բ���塣
// ��Բ�����������C����λ�����᷽��U���뾶r���߶�h��
// Բ����ĵ�����C + (h / 2) * U��C - (h / 2) * U��
// ���(X - C)^T * (I - U * U^T) * (X - C) = r^2,��X��Բ������ϵġ�
// ���Dot(U,X - C) = h / 2��(X - C)^T * (I - U * U^T) * (X - C) <= r^2��
// ��X�ڵ���C + (h / 2) * U�ϣ�
// ���Dot(U,X - C) = -h/2��(X - C)^T * (I - U * U^T) * (X - C) <= r^2��
// ��X�ڵ���C - (h / 2) * U �ϡ�

// �����ǵ�Vector3D�����顣
// ���Ϊ����C����λ�����᷽��U���뾶Real�͸߶�H��
// �����ṩ��ʼ�²��C��U������������£�m_InputsAreInitialGuess������Ϊ���桱��
// �����䱻����Ϊ���١����������������ߵ���С���˷����������ѡ��C��U��
// �ú�������ֵ����С���������0 <= e��
// ������еĵ�׼ȷ������һ��Բ���壬��e = 0��

// ������ͨ��GetExactly���׼ȷ�Ⱥ��Լ��ظ����á�
// ���C��U��Real��H����Ϊ��ʼ�²ⷴ�����������á�

// CylinderFit3<Real> fit0(points);
// Real exactly0 = fit0.GetExactly();
// Vector3D<Real> center = fit0.GetCenter();
// Vector3D<Real> axis = fit0.GetAxis();
// for (int i = 0; i <= max; ++i)
// {
//     CylinderFit3<Real> fit1(points,center,axis);
//     Real exactly1 = fit1.GetExactly();  
//     if(exactly1��exactly0û��̫��ı�ʱ)
//         break;
//     center = fit1.GetCenter();
//     axis = fit1.GetAxis(); 
//  }

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class CylinderFit3
	{
	public:
		using ClassType = CylinderFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;
		using Math = Math<Real>;

	public:
		explicit CylinderFit3(const Points& points, const Real epsilon = Math::GetZeroTolerance());
		CylinderFit3(const Points& points, const Vector3D& guessCenter, const Vector3D& guessAxis, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		// ����׼ȷ��
		Real GetExactly() const;

		const Vector3D GetCenter() const;
		const Vector3D GetAxis() const;
		Real GetRadius() const;
		Real GetHeight() const;

	private:
		void Fit3(const Points& points);
		void InitialGuess(const Points& points);
		void Update(const Points& points);
		Real ComputeHeight(const Points& points);
		void ComputeCenter(Real  average);

	private:
		Vector3D m_Center;
		Vector3D m_Axis;
		Real m_Radius;
		Real m_Height;
		Real m_Exactly;
		bool m_InputsAreInitialGuess;
		Real m_Epsilon;
	};

	using CylinderFit3f = CylinderFit3<float>;
	using CylinderFit3d = CylinderFit3<double>;
}

#endif // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H	
