///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/23 9:10)

#include "Toolset/Example/BookNetworkProgrammingToolset/BookNetworkProgrammingToolsetExport.h"

#include "BookNetworkProgrammingToolset.h"

#ifndef BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC

namespace BookNetworkProgrammingToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC
