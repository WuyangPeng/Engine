/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/25 11:06)

#include "Mathematics/MathematicsExport.h"

#include "Vector2Detail.h"
#include "Vector3Detail.h"
#include "Vector4Detail.h"
#include "VectorDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class Vector<1, float>;
    template class Vector<1, double>;
    template class Vector<2, float>;
    template class Vector<2, double>;
    template class Vector<3, float>;
    template class Vector<3, double>;
    template class Vector<4, float>;
    template class Vector<4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
