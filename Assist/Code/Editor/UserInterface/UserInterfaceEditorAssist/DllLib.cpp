///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 13:32)

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistExport.h"

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssist.h"

#ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_USER_INTERFACE_EDITOR_STATIC

namespace UserInterfaceEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_USER_INTERFACE_EDITOR_STATIC