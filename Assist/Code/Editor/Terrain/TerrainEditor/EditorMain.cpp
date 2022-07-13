///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/11 11:13)

#include "System/Helper/WindowsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Editor/Terrain/TerrainEditor/EditorHelper.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(TerrainEditor, EditorHelper, SYSTEM_TEXT("TerrainEditor"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 1024, 768)
