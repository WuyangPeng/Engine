///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/29 13:52)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
#define MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H

#include "System/Helper/EnumMacro.h"

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

    ENUM_INCREMENTABLE_OPERATOR_DEFINE(MatrixRotationAxis);
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_FLAGS_H
