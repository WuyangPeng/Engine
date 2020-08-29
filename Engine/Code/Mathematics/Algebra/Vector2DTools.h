// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:17)

// 2D向量工具类的声明
// 当向量存储的值为浮点数时，比较两向量相等，
// 请使用函数Approximate，而不是==。
// == 仅用于STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox2D.h"
#include "Vector2DOrthonormalize.h"
#include "Vector2DOrthonormalBasis.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <iosfwd>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DTools
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2DTools<Real>;
		using Vector2D = Vector2D<Real>;
		using Math = Math<Real>;
		using Vector2DOrthonormalize = Vector2DOrthonormalize<Real>;
		using Vector2DOrthonormalBasis = Vector2DOrthonormalBasis<Real>;
		using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;

	public:
		static bool Approximate(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

		static Real VectorMagnitude(const Vector2D& vector);
		static Real VectorMagnitudeSquared(const Vector2D& vector)  ;
		static Real Distance(const Vector2D& lhs, const Vector2D& rhs);
		static Real DistanceSquared(const Vector2D& lhs, const Vector2D& rhs)  ;
		static Real DotProduct(const Vector2D& lhs, const Vector2D& rhs)  ;

		// 即DotPerp	
		static Real PseudoCrossProduct(const Vector2D& lhs, const Vector2D& rhs);

		static const Vector2D ParallelVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static const Vector2D ApeakVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static Real GetVectorIncludedAngle(const Vector2D& lhs, const Vector2D& rhs)  ;

		// 垂直线相关
		// 返回 (y,-x).
		static const Vector2D GetPerp(const Vector2D& vector)  ;

		// 返回 (y,-x) / sqrt(x * x + y * y).
		static const Vector2D GetUnitPerp(const Vector2D& vector, const Real epsilon = Math::GetZeroTolerance());

		// 返回 DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = 
		// lhs.x * rhs.y - lhs.y * rhs.x.
		static Real DotPerp(const Vector2D& lhs, const Vector2D& rhs)  ;

		// 计算点的轴对齐包围盒。
		static const AxesAlignBoundingBox2D	ComputeExtremes(const std::vector<Vector2D>& vectors);

		// Gram-Schmidt正交化. 
		// 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。		
		static const Vector2DOrthonormalize Orthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

		// 输入值nonzeroVector（V）必须是一个非零向量。
		// 返回值是一个标准正交基{U，V}。
		// 返回的V为通过此函数正则化的nonzeroVector。
		// 如果你已知V是单位长度，使用U = GetPerp(V)。
		static const Vector2DOrthonormalBasis GenerateOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance());
	};

	// STL
	template <typename Real>
	bool operator== (const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

	template <typename Real>
	bool operator< (const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

	// 调试输出。
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Vector2D<Real>& vector);

	using Vector2DToolsf = Vector2DTools<float>;
	using Vector2DToolsd = Vector2DTools<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H
