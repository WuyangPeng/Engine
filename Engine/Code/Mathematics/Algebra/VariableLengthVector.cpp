/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 09:21)

#include "Mathematics/MathematicsExport.h"

#include "VariableLengthVectorDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class VariableLengthVector<float>;
    template class VariableLengthVector<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST