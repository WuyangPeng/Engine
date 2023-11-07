///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:16)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
#define MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace Mathematics
{
    enum class MatrixInitType
    {
        Zero,
        Identity
    };

    enum class MatrixMajorFlags
    {
        Row,  // �о���
        Column  // �о���
    };

    enum class MatrixRotationAxis
    {
        X,
        Y,
        Z,
        Count
    };

    enum class BandedMatrixSolveFlags
    {
        Unsolved,
        Succeed,
        Failure
    };
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
