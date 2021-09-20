// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/21 21:38)

#include "EditorHelper.h"
#include "Editor.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

ScriptEditor::EditorHelper
	::EditorHelper(HInstance hInstance,char* cmdLine,const WindowApplicationInformation& information,
			       const EnvironmentDirectory& environmentDirectory)
	:ParentType{ hInstance,cmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

ScriptEditor::EditorHelper
	::~EditorHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ScriptEditor, EditorHelper)




