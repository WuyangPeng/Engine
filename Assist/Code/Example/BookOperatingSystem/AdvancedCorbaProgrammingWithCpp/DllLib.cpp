///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/AdvancedCorbaProgrammingWithCpp/AdvancedCorbaProgrammingWithCppExport.h"

#include "AdvancedCorbaProgrammingWithCpp.h"

#ifndef BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

namespace AdvancedCorbaProgrammingWithCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC
