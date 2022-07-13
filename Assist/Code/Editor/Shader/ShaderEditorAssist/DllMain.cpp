///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 17:46)

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistFwd.h"

#ifndef BUILDING_SHADER_EDITOR_STATIC

DLL_MAIN_FUNCTION(ShaderEditorAssist);

#else  // !BUILDING_SHADER_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ShaderEditorAssist);

#endif  // BUILDING_SHADER_EDITOR_STATIC
