///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 00:00)

#include "Mathematics/MathematicsExport.h"

#include "UniqueVerticesSimplicesDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

    #include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics
{
    template class UniqueVerticesSimplices<Algebra::Vector3<float>, int, 3>;
    template class UniqueVerticesSimplices<Algebra::Vector3<double>, int, 3>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
