///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:34)

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
