///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 15:24)

#include "Editor/Data/DataEditorAssist/DataEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Data/DataEditorAssist/DataEditorAssistFwd.h"

#ifndef BUILDING_DATA_EDITOR_STATIC

DLL_MAIN_FUNCTION(DataEditorAssist);

#else  // !BUILDING_DATA_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(DataEditorAssist);

#endif  // BUILDING_DATA_EDITOR_STATIC
