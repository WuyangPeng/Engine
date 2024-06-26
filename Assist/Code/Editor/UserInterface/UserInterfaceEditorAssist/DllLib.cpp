///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:15)

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