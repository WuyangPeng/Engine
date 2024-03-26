/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 00:00)

#include "Mathematics/MathematicsExport.h"

#include "BlockLdltDecompositionDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BlockLdltDecomposition<float>;
    template class BlockLdltDecomposition<double>;

    template class BlockLdltDecomposition<float, 1, 1>;
    template class BlockLdltDecomposition<double, 1, 1>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
