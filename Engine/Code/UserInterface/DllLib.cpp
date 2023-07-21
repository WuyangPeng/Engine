///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/11 20:09)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterface.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

    #include "DllLib.h"

#else  // BUILDING_USER_INTERFACE_STATIC

namespace Animation
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_USER_INTERFACE_STATIC
