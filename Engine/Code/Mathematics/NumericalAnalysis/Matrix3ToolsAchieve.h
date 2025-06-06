///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:09)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_ACHIEVE_H

#include "Matrix3Tools.h"
#include "PolarDecompositionValueDetail.h"
#include "QDUDecompositionValueDetail.h"
#include "SingularValueDecompositionDetail.h"
#include "SingularValueDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Matrix3Tools<Real>::Matrix3Tools(const Matrix3Type& matrix) noexcept
    : matrix{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Matrix3Tools<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Matrix3Tools<Real>::SingularValueType Mathematics::Matrix3Tools<Real>::SingularValueDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 通过调用特征分解和QR分解专门针对3x3的更换。
    // 所述QDUDecomposition似乎假定输入矩阵是可逆的，
    // 但一般的QR分解具有处理非满秩矩阵。

    SingularValueType singularValue{ matrix };

    return singularValue;
}

template <typename Real>
typename Mathematics::Matrix3Tools<Real>::PolarDecompositionValueType Mathematics::Matrix3Tools<Real>::PolarDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    PolarDecompositionValueType polarDecompositionValue{ matrix };

    return polarDecompositionValue;
}

template <typename Real>
typename Mathematics::Matrix3Tools<Real>::QDUDecompositionValueType Mathematics::Matrix3Tools<Real>::QDUDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // 因子M = QR = QDU其中Q是正交（旋转），
    // D是对角（缩放），并且U是与那些在它的对角线（剪切）上三角。
    // 算法采用施密特正交（QR的算法）。
    //
    // 如果 M = [ m0 | m1 | m2 ] 和 Q = [ q0 | q1 | q2 ], 则
    //
    //   q0 = m0/|m0|
    //   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
    //   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
    //
    // 其中|V|表示矢量V的长度和A*B表示向量A和B的点积
    //  矩阵Real具有项
    //
    //   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
    //   r10 = 0      r11 = q1*m1  r12 = q1*m2
    //   r20 = 0      r21 = 0      r22 = q2*m2
    //
    // 所以 D = diag(r00,r11,r22) 和 U 具有项 u01 = r01/r00,
    // u02 = r02/r00, 和 u12 = r12/r11.

    QDUDecompositionValueType qDUDecompositionValue{ matrix };

    return qDUDecompositionValue;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_ACHIEVE_H
