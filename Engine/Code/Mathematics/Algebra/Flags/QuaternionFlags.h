/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 19:27)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H

#include "System/Helper/EnumCast.h"

namespace Mathematics
{
    enum class QuaternionClosestAxis
    {
        X = 1,
        Y = 2,
        Z = 3
    };

    static_assert(System::EnumCastUnderlying(QuaternionClosestAxis::X) == 1 && System::EnumCastUnderlying(QuaternionClosestAxis::Y) == 2 && System::EnumCastUnderlying(QuaternionClosestAxis::Z) == 3, "QuaternionClosestAxis is error.");

    enum class QuaternionFactorFlags
    {
        XYZ,
        XZY,
        YZX,
        YXZ,
        ZXY,
        ZYX
    };
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H
