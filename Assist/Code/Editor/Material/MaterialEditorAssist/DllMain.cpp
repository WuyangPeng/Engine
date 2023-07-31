///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:01)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistFwd.h"

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

DLL_MAIN_FUNCTION(MaterialEditorAssist);

#else  // !BUILDING_MATERIAL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(MaterialEditorAssist);

#endif  // BUILDING_MATERIAL_EDITOR_STATIC
