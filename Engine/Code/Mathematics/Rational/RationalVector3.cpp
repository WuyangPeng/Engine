///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:51)

#include "Mathematics/MathematicsExport.h"

#include "RationalVector3Detail.h"
#include "RationalVectorDetail.h"
#include "SignRationalDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class RationalVector3<1>;
    template class RationalVector3<2>;
    template class RationalVector3<3>;
    template class RationalVector3<4>;
    template class RationalVector3<5>;
    template class RationalVector3<6>;
    template class RationalVector3<7>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST