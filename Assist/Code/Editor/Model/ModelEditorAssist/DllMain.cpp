///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:57)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Model/ModelEditorAssist/ModelEditorAssistFwd.h"

#ifndef BUILDING_MODEL_EDITOR_STATIC

DLL_MAIN_FUNCTION(ModelEditorAssist);

#else  // !BUILDING_MODEL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ModelEditorAssist);

#endif  // BUILDING_MODEL_EDITOR_STATIC
