///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 15:32)

#include "Relation/RelationExport.h"

#include "Relation/Relation.h"

#ifndef BUILDING_RELATION_STATIC

    #include "DllLib.h"

#else  // !BUILDING_RELATION_STATIC

namespace Relation
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RELATION_STATIC
