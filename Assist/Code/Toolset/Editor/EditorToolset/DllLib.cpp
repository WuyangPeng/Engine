///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 18:15)

#include "Toolset/Editor/EditorToolset/EditorToolsetExport.h"

#include "Toolset/Editor/EditorToolset/EditorToolset.h"

#ifndef BUILDING_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_EDITOR_STATIC

namespace EditorToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EDITOR_STATIC
