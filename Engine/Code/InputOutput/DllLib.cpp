// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 14:38)

// 输入输出库（InputOutput）位于引擎的第三层，封装了引擎的输入和输出。
// 只允许调用引擎中的CoreTools库、System库，并使用boost、stlsoft工具库。

// 输入输出库包含以下模块：
// 1.   Macro（宏）
// 2.	Configuration （配置）
// 3.	InputInterface（输入接口）
// 4.	OutputInterface（输出接口）

#include "InputOutput/InputOutputExport.h"

#include "InputOutput/InputOutput.h"

#include "CoreTools/CoreToolsLib.h"
#include "System/SystemLib.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

	#include "DllLib.h"

#else // BUILDING_INPUT_OUTPUT_STATIC

	namespace InputOutput
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_INPUT_OUTPUT_STATIC