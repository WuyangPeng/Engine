// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/15 22:05)

#include "EditorHelper.h"
#include "Editor.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

SceneEditor::EditorHelper
	::EditorHelper(HInstance hInstance,char* cmdLine,const WindowApplicationInformation& information,
			       const EnvironmentDirectory& environmentDirectory)
	:ParentType{ hInstance,cmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

SceneEditor::EditorHelper
	::~EditorHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SceneEditor, EditorHelper)





