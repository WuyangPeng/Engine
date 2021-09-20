///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 0:13)

#include "Example/BookCpp/MoreExceptionalCpp/MoreExceptionalCppExport.h"

#include "MoreExceptionalCpp.h"

#ifndef BUILDING_MORE_EXCEPTIONAL_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_MORE_EXCEPTIONAL_CPP_STATIC

namespace MoreExceptionalCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MORE_EXCEPTIONAL_CPP_STATIC
