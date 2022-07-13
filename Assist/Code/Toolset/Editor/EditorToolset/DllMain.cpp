///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:34)

#include "Toolset/Editor/EditorToolset/EditorToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Editor/EditorToolset/EditorToolsetFwd.h"

#ifndef BUILDING_EDITOR_STATIC

DLL_MAIN_FUNCTION(Editor);

#else  // !BUILDING_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(Editor);

#endif  // !BUILDING_EDITOR_STATIC
