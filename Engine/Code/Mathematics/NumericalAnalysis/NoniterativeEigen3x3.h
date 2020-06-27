// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:50)

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
		// �����������ǶԳƵġ�
		explicit NoniterativeEigen3x3(const Matrix3& matrix);
		~NoniterativeEigen3x3();

		CLASS_INVARIANT_DECLARE;

		// �õ���������������ֵ�Ե�����˳��洢��
		Real GetEigenvalue(int index) const;
		const Vector3D GetEigenvector(int index) const;

	private:
		Real GetMaxValue(const Matrix3& matrix) const;
		void Compute(const Matrix3& matrix);
		void RescaleBack(Real maxValue);

		// �������ζ���ʽ�ĸ���˫�������㱻ʹ����������С����Ӱ�����������������˳�򷵻ء�
		void ComputeRoots(const Matrix3& matrix);

		// ȷ��matrix�Ƿ��е������С�����matrix�������ֵ��Ŀ��
		// ����������Ҳ�����ء�
		bool PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3D& maxRow) const;

		// ��������������
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
