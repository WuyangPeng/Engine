/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/07 10:39)

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h"

#ifndef BUILDING_FRAMEWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_FRAMEWORK_STATIC

namespace Framework
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_FRAMEWORK_STATIC