// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/19 22:20)

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistExport.h"

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MATERIAL_EDITOR_STATIC

	DLL_MAIN_FUNCTION(MaterialEditorAssist);

#else // !BUILDING_MATERIAL_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(MaterialEditorAssist);

#endif // BUILDING_MATERIAL_EDITOR_STATIC
