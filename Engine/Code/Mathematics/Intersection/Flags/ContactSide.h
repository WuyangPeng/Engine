///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 11:21)

#ifndef MATHEMATICS_INTERSECTION_CONTACT_SIDE_H
#define MATHEMATICS_INTERSECTION_CONTACT_SIDE_H

#include "System/Helper/EnumMacro.h"

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
