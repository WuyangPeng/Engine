/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/27 19:27)

#ifndef MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
#define MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H

namespace Mathematics
{
    // ����ת������ȡŷ���ǡ�
    enum class ExtractEulerResultType
    {
        // ��������Ƕ�һ�޶��ġ�
        Unique,

        // �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ�
        Sum,

        // �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ�
        Difference
    };

    enum class ExtractEulerResultOrder
    {
        XYZ,
        XZY,
        YXZ,
        YZX,
        ZXY,
        ZYX,
        XYX,
        XZX,
        YXY,
        YZY,
        ZXZ,
        ZYZ,
    };
}

#endif  // MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
