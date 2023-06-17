///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 13:58)

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