// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:07)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "HomogeneousPoint.h"
#include "AVectorOrthonormalize.h"
#include "AVectorOrthonormalBasis.h"
#include "Mathematics/Base/Float3.h"
#include "CoreTools/DataTypes/Tuple.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename T>
	class AVector : private boost::additive<AVector<T>, boost::multiplicative<AVector<T>, T>>
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = AVector<T>;
		using Math = Math<T>;
		using HomogeneousPoint = HomogeneousPoint<T>;
		using Vector3D = Vector3D<T>;
		using AlgebraTraits = AlgebraTraits<T>;

	public:
		// AVector表示仿射坐标 (x,y,z,0)。默认 (0,0,0,0)。
		AVector() noexcept;
	 
		AVector(T x, T y, T z) noexcept;
		AVector(const Float3& tuple);
		AVector(const Vector3D& rhs);
                AVector(const HomogeneousPoint& homogeneousPoint) noexcept;

		CLASS_INVARIANT_DECLARE;

		const Float3 GetFloat3() const;
                const Vector3D GetVector3D() const noexcept;

		const T& operator[] (int index) const;
		T& operator[] (int index);

		// 算术运算。

		const ClassType operator- () const;

		// 算术更新
		ClassType& operator+= (const ClassType& rhs);
		ClassType& operator-= (const ClassType& rhs);
		ClassType& operator*= (T scalar);
		ClassType& operator/= (T scalar);

		// 向量运算。
		T Length() const ;
		T SquaredLength() const;
		void Normalize(const T epsilon = Math::sm_ZeroTolerance);
		bool IsZero(const T epsilon = Math::sm_ZeroTolerance) const  ;
		bool IsNormalize(const T epsilon = Math::sm_ZeroTolerance) const  ;

		// 特殊向量
		// (0,0,0,0)
		static const AVector sm_Zero;
		// (1,0,0,0)
		static const AVector sm_UnitX;
		// (0,1,0,0)
		static const AVector sm_UnitY;
		// (0,0,1,0)	
		static const AVector sm_UnitZ;

	private:
		HomogeneousPoint m_HomogeneousPoint;
	};

	template <typename T>
	bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon);

	template <typename T>
	bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs);

	template <typename T>
	T Dot(const AVector<T>& lhs, const AVector<T>& rhs);
	template <typename T>
	const AVector<T> Cross(const AVector<T>& lhs, const AVector<T>& rhs);
	template <typename T>
	const AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon);
	template <typename T>
	const AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs);

	// 输入必须初始化为非零向量
	template <typename T>
	const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& lhs, const AVector<T>& mhs, const AVector<T>& rhs, const T epsilon);

	template <typename T>
	const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T> >& vectors, const T epsilon);

	template <typename T>
	const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& lhs, const AVector<T>& mhs, const AVector<T>& rhs);

	template <typename T>
	const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T> >& vectors);

	// 输入值nonzeroVector必须是一个非零向量。返回值是一个标准正交基{U，V, W}。
	// 返回的W为通过此函数正则化的nonzeroVector。如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
	template <typename T>
	const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon);

	template <typename T>
	const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector);

	// 输入值unitVector（W）必须是一个单位向量。
	// 返回值中的向量{U,V}是单位长度且互相垂直，
	// 且{U,V,W}是一个标准正交基。
	template <typename T>
	const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon);

	template <typename T>
	const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector);

	// 调试输出
	template <typename T>
	std::ostream& operator<< (std::ostream& outFile, const AVector<T>& vector);

	using AVectorf = AVector<float>;
	using AVectord = AVector<double>;
}

#endif // MATHEMATICS_ALGEBRA_A_VECTOR_H


