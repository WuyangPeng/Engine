///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 15:32)

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
