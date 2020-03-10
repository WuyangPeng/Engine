// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 13:23)

// 脚本库（Script）位于引擎的第三层，只允许调用引擎中的System、CoreTools库，
// 并使用boost、stlsoft和其他脚本相关的工具库。
// 主要对脚本的调用接口进行封装。

// 脚本库包含以下模块：
// 1.	Macro（宏）
// 2.   Configuration （配置）
// 3.	Interface（接口）
// 4.	Java（Java）
// 5.	Lua（lua）
// 6.	Perl（Perl）
// 7.	Python（Python）
// 8.	TCREScript（TCREScript） 

#include "Script/ScriptExport.h"

#include "Script/Script.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SCRIPT_STATIC

	#include "DllLib.h"

#else // BUILDING_SCRIPT_STATIC

	namespace Script
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCRIPT_STATIC