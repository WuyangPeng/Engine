///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 15:13)

#include "Editor.h"
#include "EditorHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

LevelEditor::EditorHelper::EditorHelper(WindowsHInstance hInstance, char* cmdLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ hInstance, cmdLine, information, environmentDirectory }
{
    SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LevelEditor, EditorHelper)
