///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 18:37)

#ifndef MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H
#define MATHEMATICS_ALGEBRA_EULER_RESULT_TYPE_H

namespace Mathematics
{
    // 从旋转矩阵提取欧拉角。
    enum class ExtractEulerResultType
    {
        // 解决方案是独一无二的。
        Unique,

        // 解决方案不是唯一的。角度之和是恒定的。
        Sum,

        // 解决方案不是唯一的。角度之差是恒定的。
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
