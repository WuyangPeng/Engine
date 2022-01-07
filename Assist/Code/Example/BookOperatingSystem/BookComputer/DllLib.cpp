///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/05 10:34)

#include "Example/BookOperatingSystem/BookComputer/BookComputerExport.h"

#include "BookComputer.h"

#ifndef BUILDING_BOOK_COMPUTER_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_COMPUTER_STATIC

namespace BookComputer
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_COMPUTER_STATIC
