///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:23)

#include "System/Helper/WindowsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Editor/Texture/TextureEditor/EditorHelper.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(TextureEditor, EditorHelper, SYSTEM_TEXT("TextureEditor"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 1024, 768)
