///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/TheArtOfComputerProgramming/TheArtOfComputerProgrammingExport.h"

#include "TheArtOfComputerProgramming.h"

#ifndef BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

    #include "DllLib.h"

#else  // BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

namespace TheArtOfComputerProgramming
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC
