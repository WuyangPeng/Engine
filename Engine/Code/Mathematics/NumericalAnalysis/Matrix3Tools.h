// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"
#include "SingularValue.h"
#include "QDUDecompositionValue.h"
#include "PolarDecompositionValue.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "CoreTools/DataTypes/TableDetail.h"

namespace Mathematics
{
	template <typename Real>
	class Matrix3Tools
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix3Tools<Real>;
		using Matrix3 = Matrix3<Real>;
		using QDUDecompositionValue = QDUDecompositionValue<Real>;
		using SingularValue = SingularValue<Real>;
		using PolarDecompositionValue = PolarDecompositionValue<Real>;

	public:
		explicit Matrix3Tools(const Matrix3& matrix);

		CLASS_INVARIANT_DECLARE;

	public:
		// ����ֵ�ֽ⣬M = L * D * Transpose(Real)������L��Real�������ģ�
		// D�ǶԽǾ�����Խ�Ԫ���ǷǸ��ġ�
		// ����ֵ��һ����Ϊleft, �ڶ�����Ϊdiag,��������ΪrightTranspose
		const SingularValue	SingularValueDecomposition() const;

		// ���ֽ⣬M = Q * S������Q�������ģ�S�ǶԳƵġ�
		// ����ʹ������ֵ�ֽ⣺
		// M = L * D * Transpose(Real) = (L * Transpose(Real)) * (Real * D * Transpose(Real)) = Q * S
		// ����Q = L * Transpose(Real)��S = Real * D * Transpose(Real)��
		// ����ֵ��һ����ΪQ���ڶ�����ΪS
		const PolarDecompositionValue PolarDecomposition() const;

		// ϵ��M = Q * D * Uʹ����������Q���ԽǾ���D�������Ǿ���U��
		// ����ֵ��һ����ΪQ���ڶ�����ΪD����������ΪU
		const QDUDecompositionValue QDUDecomposition()	const;

	private:
		Matrix3 m_Matrix;
	};

	using Matrix3Toolsf = Matrix3Tools<float>;
	using Matrix3Toolsd = Matrix3Tools<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
