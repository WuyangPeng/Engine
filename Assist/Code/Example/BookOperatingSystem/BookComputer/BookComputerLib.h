///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/05 10:35)

#ifndef BOOK_COMPUTER_LIB_H
#define BOOK_COMPUTER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_COMPUTER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookComputerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookComputer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_COMPUTER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookComputerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookComputerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_COMPUTER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_COMPUTER_LIB_H
