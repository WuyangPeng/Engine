﻿///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 00:00)

#include "Mathematics/MathematicsExport.h"

#include "OrientedBoxDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OrientedBox<2, float>;
    template class OrientedBox<2, double>;
    template class OrientedBox<3, float>;
    template class OrientedBox<3, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
