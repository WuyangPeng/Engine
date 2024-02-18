/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 19:27)

#ifndef MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
#define MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H

namespace Mathematics
{
    /// 从旋转矩阵提取欧拉角。
    /// 欧拉角的因子分解不一定是唯一的。
    /// 设轴的整数索引为(N0,N1,N2)，它必须在集合中
    ///   {(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,0,1),(2,1,0),
    ///    (0,1,0),(0,2,0),(1,0,1),(1,2,1),(2,0,2),(2,1,2)}
    // 设相应的角度为（angleN0,angleN1,angleN2）。
    // 如果结果为EulerResult::Sum，则会出现多个解，因为angleN2+angleN0是常数。
    // 如果结果为EulerResult:Difference，则会出现多个解，因为angleN2-angleN0是常数。
    // 在任何一种类型的非唯一性中，函数都返回angleN0=0。
    enum class EulerResult
    {
        // 解决方案无效（轴索引不正确）。
        Invalid,

        // 解决方案是独一无二的。
        Unique,

        // 解决方案不是唯一的。角度之和是恒定的。
        NotUniqueSum,

        // 解决方案不是唯一的。角度之差是恒定的。
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
