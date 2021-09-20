// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/21 21:31)

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistExport.h"

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCRIPT_EDITOR_STATIC

	DLL_MAIN_FUNCTION(ScriptEditorAssist);

#else // !BUILDING_SCRIPT_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(ScriptEditorAssist);

#endif // BUILDING_SCRIPT_EDITOR_STATIC
