///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:13)

#include "Editor/Font/FontEditorAssist/FontEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Font/FontEditorAssist/FontEditorAssistFwd.h"

#ifndef BUILDING_FONT_EDITOR_STATIC

DLL_MAIN_FUNCTION(FontEditorAssist);

#else  // !BUILDING_FONT_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(FontEditorAssist);

#endif  // BUILDING_FONT_EDITOR_STATIC
