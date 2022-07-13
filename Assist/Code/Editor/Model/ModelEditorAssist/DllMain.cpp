///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/08 16:57)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Model/ModelEditorAssist/ModelEditorAssistFwd.h"

#ifndef BUILDING_MODEL_EDITOR_STATIC

DLL_MAIN_FUNCTION(ModelEditorAssist);

#else  // !BUILDING_MODEL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ModelEditorAssist);

#endif  // BUILDING_MODEL_EDITOR_STATIC
