///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 10:09)

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
Mathematics::Matrix3Tools<Real>::Matrix3Tools(const Matrix3& matrix) noexcept
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
typename Mathematics::Matrix3Tools<Real>::SingularValue Mathematics::Matrix3Tools<Real>::SingularValueDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ͨ�����������ֽ��QR�ֽ�ר�����3x3�ĸ�����
    // ����QDUDecomposition�ƺ��ٶ���������ǿ���ģ�
    // ��һ���QR�ֽ���д�������Ⱦ���

    SingularValue singularValue{ matrix };

    return singularValue;
}

template <typename Real>
typename Mathematics::Matrix3Tools<Real>::PolarDecompositionValue Mathematics::Matrix3Tools<Real>::PolarDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    PolarDecompositionValue polarDecompositionValue{ matrix };

    return polarDecompositionValue;
}

template <typename Real>
typename Mathematics::Matrix3Tools<Real>::QDUDecompositionValue Mathematics::Matrix3Tools<Real>::QDUDecomposition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ����M = QR = QDU����Q����������ת����
    // D�ǶԽǣ����ţ�������U������Щ�����ĶԽ��ߣ����У������ǡ�
    // �㷨����ʩ����������QR���㷨����
    //
    // ��� M = [ m0 | m1 | m2 ] �� Q = [ q0 | q1 | q2 ], ��
    //
    //   q0 = m0/|m0|
    //   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
    //   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
    //
    // ����|V|��ʾʸ��V�ĳ��Ⱥ�A*B��ʾ����A��B�ĵ��
    //  ����Real������
    //
    //   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
    //   r10 = 0      r11 = q1*m1  r12 = q1*m2
    //   r20 = 0      r21 = 0      r22 = q2*m2
    //
    // ���� D = diag(r00,r11,r22) �� U ������ u01 = r01/r00,
    // u02 = r02/r00, �� u12 = r12/r11.

    QDUDecompositionValue qDUDecompositionValue{ matrix };

    return qDUDecompositionValue;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_ACHIEVE_H
