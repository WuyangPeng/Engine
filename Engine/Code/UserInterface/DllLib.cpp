// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 10:29)

// 用户界面库（UserInterface）位于引擎的第五层，只允许调用引擎中的System、CoreTools、Mathematics、Rendering库，
// 并使用boost、stlsoft和其他界面相关的工具库。
 
// 用户界面库包含以下模块：
// 1.	Macro（宏）
// 2.   Configuration （配置）
// 3.	Interface（接口）
// 4.	wxWidgets（wxWidgets）
// 5.	FLTK（FLTK）
// 6.	Trixul（Trixul）
// 7.	XFree86（XFree86） 

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterface.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

	#include "DllLib.h"

#else // BUILDING_USER_INTERFACE_STATIC

	namespace Animation
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INTERFACE_STATIC
