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
    /// ����ת������ȡŷ���ǡ�
    /// ŷ���ǵ����ӷֽⲻһ����Ψһ�ġ�
    /// �������������Ϊ(N0,N1,N2)���������ڼ�����
    ///   {(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,0,1),(2,1,0),
    ///    (0,1,0),(0,2,0),(1,0,1),(1,2,1),(2,0,2),(2,1,2)}
    // ����Ӧ�ĽǶ�Ϊ��angleN0,angleN1,angleN2����
    // ������ΪEulerResult::Sum�������ֶ���⣬��ΪangleN2+angleN0�ǳ�����
    // ������ΪEulerResult:Difference�������ֶ���⣬��ΪangleN2-angleN0�ǳ�����
    // ���κ�һ�����͵ķ�Ψһ���У�����������angleN0=0��
    enum class EulerResult
    {
        // ���������Ч������������ȷ����
        Invalid,

        // ��������Ƕ�һ�޶��ġ�
        Unique,

        // �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ�
        NotUniqueSum,

        // �����������Ψһ�ġ��Ƕ�֮���Ǻ㶨�ġ�
        NotUniqueDifference
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
