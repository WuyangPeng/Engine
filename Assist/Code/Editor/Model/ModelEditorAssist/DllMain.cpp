///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 15:20)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Model/ModelEditorAssist/ModelEditorAssistFwd.h"

#ifndef BUILDING_MODEL_EDITOR_STATIC

DLL_MAIN_FUNCTION(ModelEditorAssist);

#else  // !BUILDING_MODEL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ModelEditorAssist);

#endif  // BUILDING_MODEL_EDITOR_STATIC
