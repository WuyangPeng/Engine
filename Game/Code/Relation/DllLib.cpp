///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:28)

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
