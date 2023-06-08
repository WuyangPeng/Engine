///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:34)

#include "Mathematics/MathematicsExport.h"

#include "VariableMatrixDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class VariableMatrix<float>;
    template class VariableMatrix<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
