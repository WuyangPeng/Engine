// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/14 21:33)

#include "EditorHelper.h"
#include "Editor.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

ShaderEditor::EditorHelper
	::EditorHelper(HInstance hInstance,char* cmdLine,const WindowApplicationInformation& information,
			       const EnvironmentDirectory& environmentDirectory)
	:ParentType{ hInstance,cmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

ShaderEditor::EditorHelper
	::~EditorHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ShaderEditor, EditorHelper)





