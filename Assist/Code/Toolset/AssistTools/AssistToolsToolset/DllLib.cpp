///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:30)

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetExport.h"

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolset.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

    #include "DllLib.h"

#else  // BUILDING_ASSIST_TOOLS_STATIC

namespace AssistToolsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ASSIST_TOOLS_STATIC