///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:38)

#include "Mathematics/MathematicsExport.h"

#include "SparseMatrixConstIteratorDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class SparseMatrixConstIterator<float>;
    template class SparseMatrixConstIterator<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
