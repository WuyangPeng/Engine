// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/13 23:44)

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistExport.h"

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SHADER_EDITOR_STATIC

	DLL_MAIN_FUNCTION(ShaderEditorAssist);

#else // !BUILDING_SHADER_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(ShaderEditorAssist);

#endif // BUILDING_SHADER_EDITOR_STATIC
