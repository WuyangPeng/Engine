///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 20:27)

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
