///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/TheCppStandardLibrary/TheCppStandardLibraryExport.h"

#include "TheCppStandardLibrary.h"

#ifndef BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

    #include "DllLib.h"

#else  // BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

namespace TheCppStandardLibrary
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC
