///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:43)

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
