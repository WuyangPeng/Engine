// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:17)

// 2D���������������
// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Approximate��������==��
// == ������STL
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

		// ��DotPerp	
		static Real PseudoCrossProduct(const Vector2D& lhs, const Vector2D& rhs);

		static const Vector2D ParallelVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static const Vector2D ApeakVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static Real GetVectorIncludedAngle(const Vector2D& lhs, const Vector2D& rhs)  ;

		// ��ֱ�����
		// ���� (y,-x).
		static const Vector2D GetPerp(const Vector2D& vector)  ;

		// ���� (y,-x) / sqrt(x * x + y * y).
		static const Vector2D GetUnitPerp(const Vector2D& vector, const Real epsilon = Math::GetZeroTolerance());

		// ���� DotPerp((lhs.x,lhs.y),(rhs.x,rhs.y)) = 
		// lhs.x * rhs.y - lhs.y * rhs.x.
		static Real DotPerp(const Vector2D& lhs, const Vector2D& rhs)  ;

		// ������������Χ�С�
		static const AxesAlignBoundingBox2D	ComputeExtremes(const std::vector<Vector2D>& vectors);

		// Gram-Schmidt������. 
		// �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����		
		static const Vector2DOrthonormalize Orthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

		// ����ֵnonzeroVector��V��������һ������������
		// ����ֵ��һ����׼������{U��V}��
		// ���ص�VΪͨ���˺������򻯵�nonzeroVector��
		// �������֪V�ǵ�λ���ȣ�ʹ��U = GetPerp(V)��
		static const Vector2DOrthonormalBasis GenerateOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance());
	};

	// STL
	template <typename Real>
	bool operator== (const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

	template <typename Real>
	bool operator< (const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Vector2D<Real>& vector);

	using Vector2DToolsf = Vector2DTools<float>;
	using Vector2DToolsd = Vector2DTools<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_H
