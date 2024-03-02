///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/18 17:33)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_TYPE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_TYPE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics::Algebra
{
    enum class RotationType
    {
        IsMatrix,
        IsQuaternion,
        IsAxisAngle,
        IsEulerAngles
    };
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_TYPE_H
