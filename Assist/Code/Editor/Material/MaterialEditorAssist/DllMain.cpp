///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:01)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistFwd.h"

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

DLL_MAIN_FUNCTION(MaterialEditorAssist);

#else  // !BUILDING_MATERIAL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(MaterialEditorAssist);

#endif  // BUILDING_MATERIAL_EDITOR_STATIC
