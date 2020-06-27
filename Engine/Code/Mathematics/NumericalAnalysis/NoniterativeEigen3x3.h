// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class NoniterativeEigen3x3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = NoniterativeEigen3x3<Real>;
		using Matrix3 = Matrix3<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		// 输入矩阵必须是对称的。
		explicit NoniterativeEigen3x3(const Matrix3& matrix);
		~NoniterativeEigen3x3();

		CLASS_INVARIANT_DECLARE;

		// 得到特征向量。特征值以递增的顺序存储。
		Real GetEigenvalue(int index) const;
		const Vector3D GetEigenvector(int index) const;

	private:
		Real GetMaxValue(const Matrix3& matrix) const;
		void Compute(const Matrix3& matrix);
		void RescaleBack(Real maxValue);

		// 计算三次多项式的根。双精度运算被使用在由于最小化的影响减消除。根按递增顺序返回。
		void ComputeRoots(const Matrix3& matrix);

		// 确定matrix是否有的正的列。返回matrix的最大量值项目。
		// 它包含的列也被返回。
		bool PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3D& maxRow) const;

		// 计算特征向量。
		void ComputeVectors(const Matrix3& matrix, Vector3D& vector, int firstIndex, int secondIndex, int thirdIndex);

	private:
		static constexpr auto sm_EigenMax = 3;

		Real m_Eigenvalue[sm_EigenMax];
		Vector3D m_Eigenvector[sm_EigenMax];
	};

	using NoniterativeEigen3x3f = NoniterativeEigen3x3<float>;
	using NoniterativeEigen3x3d = NoniterativeEigen3x3<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
