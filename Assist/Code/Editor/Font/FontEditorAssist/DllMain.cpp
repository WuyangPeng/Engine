///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 11:16)

#include "Editor/Font/FontEditorAssist/FontEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Font/FontEditorAssist/FontEditorAssistFwd.h"

#ifndef BUILDING_FONT_EDITOR_STATIC

DLL_MAIN_FUNCTION(FontEditorAssist);

#else  // !BUILDING_FONT_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(FontEditorAssist);

#endif  // BUILDING_FONT_EDITOR_STATIC
