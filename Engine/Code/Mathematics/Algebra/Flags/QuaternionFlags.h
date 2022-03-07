///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/29 13:53)

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
