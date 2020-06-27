// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:09)

// 轴对齐包围盒4D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector4D.h"

namespace Mathematics
{
	template <typename T>
	class AxesAlignBoundingBox4D
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = AxesAlignBoundingBox4D<T>;
		using Vector4D = Vector4D<T>;

	public:
		explicit AxesAlignBoundingBox4D(const Vector4D& minPoint, const Vector4D& maxPoint);

		template <typename RhsType>
		AxesAlignBoundingBox4D(const AxesAlignBoundingBox4D<RhsType>& aabb);

		CLASS_INVARIANT_DECLARE;

		const Vector4D GetMinPoint() const;
		const Vector4D GetMaxPoint() const;

	private:
		void Recalculate();

	private:
		Vector4D m_MinPoint;
		Vector4D m_MaxPoint;
	};

	using AxesAlignBoundingBox4Df = AxesAlignBoundingBox4D<float>;
	using AxesAlignBoundingBox4Dd = AxesAlignBoundingBox4D<double>;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H