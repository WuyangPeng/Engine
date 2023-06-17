///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 13:32)

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistFwd.h"

#ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

DLL_MAIN_FUNCTION(UserInterfaceEditor);

#else  // !BUILDING_USER_INTERFACE_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterfaceEditor);

#endif  // !BUILDING_USER_INTERFACE_EDITOR_STATIC