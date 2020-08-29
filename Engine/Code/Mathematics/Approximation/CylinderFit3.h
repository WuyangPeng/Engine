// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:27)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H

#include "Mathematics/MathematicsDll.h"

// 最小二乘拟合数据(x,y,z)到一个有限圆柱体。
// 该圆柱体具有中心C，单位长度轴方向U，半径r，高度h。
// 圆柱体的底盘在C + (h / 2) * U和C - (h / 2) * U。
// 如果(X - C)^T * (I - U * U^T) * (X - C) = r^2,点X是圆柱体壁上的。
// 如果Dot(U,X - C) = h / 2和(X - C)^T * (I - U * U^T) * (X - C) <= r^2，
// 点X在底盘C + (h / 2) * U上，
// 如果Dot(U,X - C) = -h/2和(X - C)^T * (I - U * U^T) * (X - C) <= r^2，
// 点X在底盘C - (h / 2) * U 上。

// 输入是点Vector3D的数组。
// 输出为中心C，单位长度轴方向U，半径Real和高度H。
// 可以提供初始猜测的C和U。在这种情况下，m_InputsAreInitialGuess被设置为“真”。
// 否则其被设置为“假”，函数将首先用线的最小二乘法拟合数据来选择C和U。
// 该函数返回值是最小二乘拟合误差，0 <= e。
// 如果所有的点准确的落在一个圆柱体，则e = 0。

// 您可以通过GetExactly检查准确度和自己重复调用。
// 输出C，U，Real和H可作为初始猜测反馈到函数调用。

// CylinderFit3<Real> fit0(points);
// Real exactly0 = fit0.GetExactly();
// Vector3D<Real> center = fit0.GetCenter();
// Vector3D<Real> axis = fit0.GetAxis();
// for (int i = 0; i <= max; ++i)
// {
//     CylinderFit3<Real> fit1(points,center,axis);
//     Real exactly1 = fit1.GetExactly();  
//     if(exactly1和exactly0没有太大改变时)
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

		// 返回准确度
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
