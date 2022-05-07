///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:20)

#include "AssistTools/AssistToolsExport.h"

#include "AssistTools/AssistTools.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

    #include "DllLib.h"

#else  // BUILDING_ASSIST_TOOLS_STATIC

namespace AssistTools
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ASSIST_TOOLS_STATIC
