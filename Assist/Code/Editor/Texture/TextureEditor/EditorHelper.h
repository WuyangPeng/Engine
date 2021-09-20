// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/18 23:48)

#ifndef TEXTURE_EDITOR_EDITOR_HELPER_H
#define TEXTURE_EDITOR_EDITOR_HELPER_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace TextureEditor
{
	using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
	class EditorHelper : public WindowMainFunctionHelper
	{
	public:
		using ClassType = EditorHelper;
		using ParentType = WindowMainFunctionHelper;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;

	public:
		EditorHelper(HInstance hInstance, char* cmdLine, const WindowApplicationInformation& information,
					 const EnvironmentDirectory& environmentDirectory);
		virtual ~EditorHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // TEXTURE_EDITOR_EDITOR_HELPER_H
