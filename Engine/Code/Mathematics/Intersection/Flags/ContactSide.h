///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 10:39)

#ifndef MATHEMATICS_INTERSECTION_CONTACT_SIDE_H
#define MATHEMATICS_INTERSECTION_CONTACT_SIDE_H

#include "System/Helper/EnumOperator.h"

namespace Mathematics
{
    // 接触面（投影间隔的顺序）。
    enum class ContactSide
    {
        Left,
        Right,
        None
    };
}

#endif  // MATHEMATICS_INTERSECTION_CONTACT_SIDE_H
