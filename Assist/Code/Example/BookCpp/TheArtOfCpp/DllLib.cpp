///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#include "Example/BookCpp/TheArtOfCpp/TheArtOfCppExport.h"

#include "TheArtOfCpp.h"

#ifndef BUILDING_THE_ART_OF_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_THE_ART_OF_CPP_STATIC

namespace TheArtOfCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_ART_OF_CPP_STATIC
