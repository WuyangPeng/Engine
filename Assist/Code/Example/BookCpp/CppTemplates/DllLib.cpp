///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/07 18:48)

#include "Example/BookCpp/CppTemplates/CppTemplatesExport.h"

#include "CppTemplates.h"

#ifndef BUILDING_CPP_TEMPLATES_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_TEMPLATES_STATIC

namespace CppTemplates
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_TEMPLATES_STATIC
