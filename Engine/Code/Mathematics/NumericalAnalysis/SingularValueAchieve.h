///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_ACHIEVE_H

#include "SingularValue.h"
#include "SingularValueDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::SingularValue<Real>::SingularValue(const Matrix3& matrix)
    : left{}, diagonal{}, rightTranspose{}
{
    Calculate(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SingularValue<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::SingularValue<Real>::Calculate(const Matrix3& matrix)
{
    // ͨ�����������ֽ��QR�ֽ�ר�����3x3�ĸ�����
    // ����QDUDecomposition�ƺ��ٶ���������ǿ���ģ���һ���QR�ֽ���д�������Ⱦ���

    VariableMatrix<Real> variableMatrix{ matrix };

    Mathematics::SingularValueDecomposition<Real> decomposition{ variableMatrix };

    left = decomposition.GetLeftMatrix().GetMatrix3();
    diagonal = decomposition.GetDiagonalMatrix().GetMatrix3();
    rightTranspose = decomposition.GetRightTransposeMatrix().GetMatrix3();
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::SingularValue<Real>::GetLeftMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return left;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::SingularValue<Real>::GetDiagonalMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return diagonal;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::SingularValue<Real>::GetRightTransposeMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rightTranspose;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_ACHIEVE_H
