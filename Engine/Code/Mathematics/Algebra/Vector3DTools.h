// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:18)

// 3D���������������
// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Approximate��������==��
// == ������STL
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxesAlignBoundingBox3D.h"
#include "Vector3DOrthonormalize.h"
#include "Vector3DOrthonormalBasis.h"
#include "CoreTools/DataTypes/Tuple.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <iosfwd>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DTools
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector3DTools<Real>;
		using Vector3D = Vector3D<Real>;
		using Function = Real(*)(Real);
		using Math = Math<Real>;
		using Vector3DTuple = CoreTools::Tuple<3, Vector3D>;
		using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
		using Vector3DOrthonormalize = Vector3DOrthonormalize<Real>;
		using Vector3DOrthonormalBasis = Vector3DOrthonormalBasis<Real>;

	public:
		static bool Approximate(const Vector3D& lhs, const Vector3D& rhs,
								const Real epsilon = Math::sm_ZeroTolerance) noexcept;

		static Real VectorMagnitude(const Vector3D& vector) noexcept;
		static Real VectorMagnitudeSquared(const Vector3D& vector) noexcept;
		static Real DotProduct(const Vector3D& lhs, const Vector3D& rhs);

		// ���ʹ�õ������ֵĹ�����㡣 
		// ��ע�⣬ĳЩͼ��APIʹ�����ֵĹ��� 
		// ����������ʹ����Щ����������������͸�һ�����������ֵ�API��
		// ������Ҫ���ĵ�ʸ�����ţ��滻ÿ�����ֵcΪ-c����
		static const Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs) noexcept;
		static const Vector3D CrossProductWithReduceMultiplication(const Vector3D& lhs, const Vector3D& rhs);
		static const Vector3D UnitCrossProduct(const Vector3D& lhs, const Vector3D& rhs,
											   const Real epsilon = Math::sm_ZeroTolerance);

		static Real Distance(const Vector3D& lhs, const Vector3D& rhs);
		static Real DistanceSquared(const Vector3D& lhs, const Vector3D& rhs);
		static const Vector3D ParallelVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::sm_ZeroTolerance);
		static const Vector3D ApeakVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon = Math::sm_ZeroTolerance);
		static const Vector3D ReflectionVector(const Vector3D& ray, const Vector3D& normal);
		static const Vector3D RefractionVector(const Vector3D& ray, const Vector3D& normal, Real consistencyRatio);
		static const Vector3D FeatheringOutZAxes(const Vector3D& vector, Function function);
		static const Vector3D TwistZAxes(const Vector3D& vector, Function function);
		static const Vector3D BendYAxes(const Vector3D& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax);
		static Real ScalarTripleProduct(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs);
		static Real GetVectorIncludedAngle(const Vector3D& lhs, const Vector3D& rhs);

		// ������������Χ�С�
		static const AxesAlignBoundingBox3D	ComputeExtremes(const std::vector<Vector3D>& vectors);

		// Gram-Schmidt������. 
		// �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
		static const Vector3DOrthonormalize Orthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs,
														   const Real epsilon = Math::sm_ZeroTolerance);
		static const Vector3DOrthonormalize Orthonormalize(const std::vector<Vector3D> vectors, const Real epsilon = Math::sm_ZeroTolerance);

		// ����ֵnonzeroVector��W��������һ������������
		// ����ֵ��һ����׼������{U��V, W}��
		// ���ص�WΪͨ���˺������򻯵�nonzeroVector��
		// �������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
		static const Vector3DOrthonormalBasis  GenerateOrthonormalBasis(const Vector3D& nonzeroVector, const Real epsilon = Math::sm_ZeroTolerance);

		// ����ֵnonzeroVector��W��������һ����λ������
		// ����ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ��
		// ��{U,V,W}��һ����׼��������
		static const Vector3DOrthonormalBasis GenerateComplementBasis(const Vector3D& unitVector, const Real epsilon = Math::sm_ZeroTolerance);
	};

	// STL
	template <typename Real>
	bool operator== (const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

	template <typename Real>
	bool operator< (const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Vector3D<Real>& vector);

	using Vector3DToolsf = Vector3DTools<float>;
	using Vector3DToolsd = Vector3DTools<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_H
