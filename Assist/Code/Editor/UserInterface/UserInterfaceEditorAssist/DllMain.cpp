///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 14:38)

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistFwd.h"

#ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

DLL_MAIN_FUNCTION(UserInterfaceEditor);

#else  // !BUILDING_USER_INTERFACE_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterfaceEditor);

#endif  // !BUILDING_USER_INTERFACE_EDITOR_STATIC