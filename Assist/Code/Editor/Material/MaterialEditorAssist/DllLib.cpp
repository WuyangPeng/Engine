///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:01)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssist.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATERIAL_EDITOR_STATIC

namespace MaterialEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATERIAL_EDITOR_STATIC
