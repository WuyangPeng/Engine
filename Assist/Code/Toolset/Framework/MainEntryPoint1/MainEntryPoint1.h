// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/25 11:37)

#ifndef MAIN_ENTRY_POINT1_H
#define MAIN_ENTRY_POINT1_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperBase.h"

namespace Framework
{
	class MainEntryPoint1 final : public ConsoleMainFunctionHelperBase
	{
	public:
		using ClassType = MainEntryPoint1;
		using ParentType = ConsoleMainFunctionHelperBase;

	public:
		MainEntryPoint1(int argc, char** argv, const String& consoleTitle,const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;

		int DoRun() override;
	};
}

#endif // MAIN_ENTRY_POINT1_H
