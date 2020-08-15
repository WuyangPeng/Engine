// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:18)

// 4D向量类的声明
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Vector4D : private boost::additive<Vector4D<Real>,
							 boost::multiplicative<Vector4D<Real>, Real,
							 boost::totally_ordered<Vector4D<Real> > > >
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector4D<Real>;
		using Tuple4 = CoreTools::Tuple<4, Real>;
		using Math = Math<Real>;
		using ToolsType = Vector4DTools<Real>;

	public:
		Vector4D() noexcept;
		Vector4D(const Tuple4& tuple);
		Vector4D(Real x, Real y, Real z, Real w);

		Vector4D& operator= (const Tuple4& tuple);

		template <typename RhsType>
		Vector4D(const Vector2D<RhsType>& vector);
		template <typename RhsType>
		Vector4D(const Vector3D<RhsType>& vector);
		template <typename RhsType>
		Vector4D(const Vector4D<RhsType>& vector);

		CLASS_INVARIANT_DECLARE;

		// 坐标访问
		Real GetXCoordinate() const;
		Real GetYCoordinate() const;
		Real GetZCoordinate() const;
		Real GetWCoordinate() const;
		bool IsZero(const Real epsilon = Math::sm_ZeroTolerance) const;

		void ZeroOut();
		void SetCoordinate(Real x, Real y, Real z, Real w);
		void SetXCoordinate(Real x);
		void SetYCoordinate(Real y);
		void SetZCoordinate(Real z);
		void SetWCoordinate(Real w);
		void Normalize(const Real epsilon = Math::sm_ZeroTolerance);
		void ProjectionNormalization(const Real epsilon = Math::sm_ZeroTolerance);

		const ClassType operator-() const;
		const Real& operator[](unsigned int index) const;

		Real& operator[] (unsigned int index);
		ClassType& operator+= (const ClassType& rhs);
		ClassType& operator-= (const ClassType& rhs);
		ClassType& operator*= (Real rhs);
		ClassType& operator/= (Real rhs);

		// 特殊Vector4D
		static const Vector4D sm_Zero; // (0,0,0,0)
		static const Vector4D sm_UnitX; // (1,0,0,0)
		static const Vector4D sm_UnitY; // (0,1,0,0)
		static const Vector4D sm_UnitZ; // (0,0,1,0)
		static const Vector4D sm_UnitW; // (0,0,0,1)
		static const Vector4D sm_One; // (1,1,1,1)

		const ClassType GetMove(Real t, const ClassType& velocity) const;

	private:
		using Vector4DTools = Vector4DTools<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	private:
		Tuple4 m_Tuple;
	};

	using Vector4Df = Vector4D<float>;
	using Vector4Dd = Vector4D<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_4D_H
