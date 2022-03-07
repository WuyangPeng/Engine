///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/29 13:52)

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
