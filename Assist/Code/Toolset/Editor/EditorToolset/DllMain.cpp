// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/12 1:24)

#include "Toolset/Editor/EditorToolset/EditorToolsetExport.h"

#include "Toolset/Editor/EditorToolset/EditorToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EDITOR_STATIC

	DLL_MAIN_FUNCTION(Editor);

#else // !BUILDING_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(Editor);

#endif // !BUILDING_EDITOR_STATIC
