// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// 除了最小二乘的一个大圆，输入向量投影到圆。
	// 最小角的扇形(可能的)包含点计算。
	// 弧的端点的扇形被返回。返回的端点A0和A1是垂直于返回的法线N。
	// 此外,当你查看弧通过观察平面的大圆的 N方向,圆弧是遍历逆时针从A0到A1。
	template <typename Real>
	class GreatArcFit3
	{
	public:
		using ClassType = GreatArcFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;

	public:
		explicit GreatArcFit3(const Points& points);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal() const;
		const Vector3D GetArcEnd0() const;
		const Vector3D GetArcEnd1() const;

	private:
		void Calculate(const Points& points);

	private:
		Vector3D m_Normal;
		Vector3D m_ArcEnd0;
		Vector3D m_ArcEnd1;
	};

	using GreatArcFit3d = GreatArcFit3<double>;
	using GreatArcFit3f = GreatArcFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
