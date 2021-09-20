// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/13 23:43)

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistExport.h"

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SHADER_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_SHADER_EDITOR_STATIC

	namespace ShaderEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SHADER_EDITOR_STATIC
