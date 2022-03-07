///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/03 20:16)

#include "Mathematics/MathematicsExport.h"

#include "Vector2InformationDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class Vector2Information<float>;
    template class Vector2Information<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST