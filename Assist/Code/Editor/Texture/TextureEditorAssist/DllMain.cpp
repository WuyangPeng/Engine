///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 13:47)

#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Texture/TextureEditorAssist/TextureEditorAssistFwd.h"

#ifndef BUILDING_TEXTURE_EDITOR_STATIC

DLL_MAIN_FUNCTION(TextureEditorAssist);

#else  // !BUILDING_TEXTURE_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(TextureEditorAssist);

#endif  // BUILDING_TEXTURE_EDITOR_STATIC
