///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 14:55)

#include "System/Helper/WindowsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Editor/Shader/ShaderEditor/EditorHelper.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(ShaderEditor, EditorHelper, SYSTEM_TEXT("ShaderEditor"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 1024, 768)
