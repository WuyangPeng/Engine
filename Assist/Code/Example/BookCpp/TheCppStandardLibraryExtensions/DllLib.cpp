///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:51)

#include "Example/BookCpp/TheCppStandardLibraryExtensions/TheCppStandardLibraryExtensionsExport.h"

#include "TheCppStandardLibraryExtensions.h"

#ifndef BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC

    #include "DllLib.h"

#else  // BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC

namespace TheCppStandardLibraryExtensions
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC
