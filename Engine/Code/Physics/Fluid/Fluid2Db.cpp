///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 15:10)

#include "Physics/PhysicsExport.h"

#include "Fluid2DbDetail.h"

#ifdef PHYSICS_TEMPLATE_TEST

namespace Physics
{
    template class Fluid2Db<float>;
    template class Fluid2Db<double>;
}

#endif  // PHYSICS_TEMPLATE_TEST
