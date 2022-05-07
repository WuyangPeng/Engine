///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:13)

#include "Physics/PhysicsExport.h"

#include "Fluid3DaDetail.h"

#ifdef PHYSICS_TEMPLATE_TEST

namespace Physics
{
    template class Fluid3Da<float>;
    template class Fluid3Da<double>;
}

#endif  // PHYSICS_TEMPLATE_TEST
