// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/06 11:09)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Ellipse2Coefficients.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <type_traits> 
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Ellipse2
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ellipse2<Real>;
		using Math = Math<Real>;
		using Vector2D = Vector2D<Real>;
		using Matrix2 = Matrix2<Real>;
		using Ellipse2Coefficients = Ellipse2Coefficients<Real>;
		using Vector2DTools = Vector2DTools<Real>;

	public:	
		// 椭圆具有中心K，轴方向U[0]和U[1]（两个都是单位长度向量），
		// 和扩展e[0] 和 e[1]（两个都是均为正数）。
		// 点X = K+y[0]*U[0]+y[1]*U[1]是椭圆时，
		// 当(y[0]/e[0])^2+(y[1]/e[1])^2 = 1。 
		// 该试验椭圆内部的点使用“<=”代替“=”。
		// 椭圆的代数表示是
		//   1 = (X-K)^T * (U[0]*U[0]^T/e[0]^2 + U[1]*U[1]^T/e[1]^2) * (X-K)
		//     = (X-K)^T * M * (X-K)
		// 其中，上标T表示转置。观察到U[i]*U[i]^T是一个矩阵，而不是标量积。
		// 矩阵M是对称的。椭圆也由一元二次方程表示
		//   0 = a0 + a1*x[0] + a2*x[1] + a3*x[0]^2 + a4*x[0]*x[1] + a5*x[1]^2
		//     = a0 + [a1 a2]*X + X^T*[a3   a4/2]*X
		//                            [a4/2 a5  ]
		//     = C + B^T*X + X^T*A*X	
		// 其中X = (x[0],x[1])。这个等式可以被分解到(X-K)^T*M*(X-K) = 1，
		// 其中K = -A^{-1}*B/2, M = A/(B^T*A^{-1}*B/4-C)。
		// 为椭圆形时，M必须具有所有特征值为正。

		Ellipse2 (const Vector2D& center, const Vector2D& axis0,const Vector2D& axis1, 
				  const Real extent0, const Real extent1,const Real epsilon = Math::sm_ZeroTolerance);

		explicit Ellipse2(const Ellipse2Coefficients& coefficients,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetCenter() const;
		const Vector2D GetAxis0() const;
		const Vector2D GetAxis1() const;
		Real GetExtent0() const;
		Real GetExtent1() const;

		// 计算 M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
		const Matrix2 GetMatrix () const;

		// 计算 M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
		const Matrix2 GetMatrixInverse () const;

		// 构建二次方程式，表示椭圆的系数。 		
		const Ellipse2Coefficients ToCoefficients () const;	

		// 构建m_Center，m_Axis和m_Extent从二次方程。
		// 如果输入系数不能表示一个椭圆，则抛出异常。
		void FromCoefficients (const Ellipse2Coefficients& coefficients,const Real epsilon = Math::sm_ZeroTolerance);
		
		// 计算的二次函数 Q(X) = (X-K)^T * M * (X-K) - 1.
		Real Evaluate (const Vector2D& point) const;

		// 测试输入点是否在椭圆形内部或边上。
		// 该点被包含当Q(X) <= 0，其中Q(X)函数Evaluate()。
		bool Contains (const Vector2D& point) const;

		const ClassType GetMove(Real t, const Vector2D& velocity) const;

	private:
		Vector2D m_Center;
		Vector2D m_Axis[2];
		Real m_Extent[2];
		Real m_Epsilon;	
	};

	template <typename Real>
	bool Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, const Real epsilon);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Ellipse2<Real>& line);

	using Ellipse2f = Ellipse2<float>;
	using Ellipse2d = Ellipse2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_ELLIPSE2_H
