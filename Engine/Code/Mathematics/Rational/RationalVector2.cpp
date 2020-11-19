///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:51)

#include "Mathematics/MathematicsExport.h"

#include "RationalVector2Detail.h"
#include "RationalVectorDetail.h"
#include "SignRationalDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class RationalVector2<1>;
    template class RationalVector2<2>;
    template class RationalVector2<3>;
    template class RationalVector2<4>;
    template class RationalVector2<5>;
    template class RationalVector2<6>;
    template class RationalVector2<7>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST