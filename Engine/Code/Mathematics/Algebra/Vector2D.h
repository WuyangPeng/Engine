// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:16)

// 2D�����������
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BarycentricCoordinates.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class Vector2D : private boost::additive<Vector2D<Real>, boost::multiplicative<Vector2D<Real>, Real,
							 boost::totally_ordered<Vector2D<Real> > > >
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2D<Real>;
		using Math = Math<Real>;
		using Tuple2 = CoreTools::Tuple<2, Real>;
		using Tuple3 = CoreTools::Tuple<3, Real>;
		using BarycentricCoordinates = BarycentricCoordinates<Real, 3>;
		using ToolsType = Vector2DTools<Real>;

	public:
		Vector2D() noexcept;
		Vector2D(const Tuple2& tuple);
		Vector2D(Real x, Real y) noexcept;

		Vector2D& operator= (const Tuple2& tuple);

		template <typename RhsType>
		Vector2D(const Vector2D<RhsType>& vector);
		template <typename RhsType>
		Vector2D(const Vector3D<RhsType>& vector);
		template <typename RhsType>
		Vector2D(const Vector4D<RhsType>& vector);

		CLASS_INVARIANT_DECLARE;

		// �������
		Real GetXCoordinate() const;
		Real GetYCoordinate() const;
		bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const;

		void ZeroOut() noexcept;
		void SetCoordinate(Real x, Real y);
		void SetXCoordinate(Real x);
		void SetYCoordinate(Real y);
		void Normalize(const Real epsilon = Math::GetZeroTolerance());

		bool IsNormalize(const Real epsilon = Math::GetZeroTolerance()) const;

		const ClassType operator- () const;
		const Real& operator[](unsigned int index) const;

		Real& operator[] (unsigned int index);
		ClassType& operator+= (const ClassType& rhs);
		ClassType& operator-= (const ClassType& rhs);

		ClassType& operator*= (Real rhs);
		ClassType& operator/= (Real rhs);

		// ����Vector2D
		static const Vector2D sm_Zero; // (0,0)
		static const Vector2D sm_UnitX; // (1,0)
		static const Vector2D sm_UnitY; // (0,1)
		static const Vector2D sm_One; // (1,1)

		// ����ڼ������V���������굽������<V0,V1,V2>
		// V = b0 * V0 + b1 * V1 + b2 * V2��
		// ����b0 + b1 + b2 = 1��
		// ���ҽ���{V0��V1��V2}�������޹���ʱ����ֵ����Ч�ġ� 
		// ��ֵ�ϣ����� |det[V0 V1 V2]| <= epsilon��	
		const BarycentricCoordinates GetBarycentrics(const ClassType& firstVector, const ClassType& secondVector,
													 const ClassType& thirdVector, const Real epsilon = Math::GetZeroTolerance()) const;

		const ClassType GetMove(Real t, const ClassType& velocity) const;

	private:
		using Vector2DTools = Vector2DTools<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	private:
		Tuple2 m_Tuple;
	};

	using Vector2Df = Vector2D<float>;
	using Vector2Dd = Vector2D<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_H
