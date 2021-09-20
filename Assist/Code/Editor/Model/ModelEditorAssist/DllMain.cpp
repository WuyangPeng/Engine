// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/18 20:50)

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistExport.h"

#include "Editor/Model/ModelEditorAssist/ModelEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MODEL_EDITOR_STATIC

	DLL_MAIN_FUNCTION(ModelEditorAssist);

#else // !BUILDING_MODEL_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(ModelEditorAssist);

#endif // BUILDING_MODEL_EDITOR_STATIC
