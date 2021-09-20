// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/26 13:24)

#ifndef WIN_MAIN_ENTRY_POINT3_H
#define WIN_MAIN_ENTRY_POINT3_H

#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h" 
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Framework
{
	using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

	class WinMainEntryPoint3 final : public BaseType
	{
	public:
		using ClassType = WinMainEntryPoint3;
		using ParentType = BaseType;

	public:
		WinMainEntryPoint3(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // WIN_MAIN_ENTRY_POINT3_H