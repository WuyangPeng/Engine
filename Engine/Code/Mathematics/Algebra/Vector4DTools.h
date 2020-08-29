// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:19)

// 4D���������������
// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Approximate��������==��
// == ������STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4D.h"

#include <type_traits>
#include <iosfwd>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4DTools
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector4DTools;
		using Math = Math<Real>;
		using Vector4D = Vector4D<Real>;
		using AxesAlignBoundingBox4D = AxesAlignBoundingBox4D<Real>;

	public:
		static bool Approximate(const Vector4D& lhs, const Vector4D& rhs,
								const Real epsilon = Math::GetZeroTolerance());

		static Real VectorMagnitude(const Vector4D& vector);
		static Real VectorMagnitudeSquared(const Vector4D& vector);
		static Real Distance(const Vector4D& lhs, const Vector4D& rhs);
		static Real DistanceSquared(const Vector4D& lhs, const Vector4D& rhs);
		static Real DotProduct(const Vector4D& lhs, const Vector4D& rhs);

		static const Vector4D ParallelVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static const Vector4D ApeakVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon = Math::GetZeroTolerance());
		static Real GetVectorIncludedAngle(const Vector4D& lhs, const Vector4D& rhs);

		// ������������Χ�С�
		static const AxesAlignBoundingBox4D	ComputeExtremes(const std::vector<Vector4D>& vectors);
	};

	// STL
	template <typename Real>
	bool operator== (const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);

	template <typename Real>
	bool operator< (const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Vector4D<Real>& vector);

	using Vector4DToolsf = Vector4DTools<float>;
	using Vector4DToolsd = Vector4DTools<double>;
};

#endif // MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_H
