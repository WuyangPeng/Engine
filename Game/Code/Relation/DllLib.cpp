///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:11)

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
