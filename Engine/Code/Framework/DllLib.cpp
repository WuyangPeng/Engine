// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 0:01)

// 框架库（Framework）位于引擎的最上层，封装了与操作系统相关的基础框架（包括Windows、Linux、Android和Macintosh），但不直接调用系统API。
// 并对引擎游戏中间层进行基础设计，实现各个系统的分离。
// 框架库允许调用引擎中的所有库，并使用boost工具库。

// 框架库包含以下模块：
// 1.  Helper（帮助）
// 2.  MainFunctionHelper（主函数帮助）
// 3.  WindowCreate（窗口创建）
// 4.  WindowProcess（窗口进程）
// 5.  WindowRegister（窗口注册）
// 6.  Application（应用）
// 7.  MiddleLayer（中间层）
// 8.  WindowsAPIFrame（WindowsAPI框架）
// 9.  OpenGLGlutFrame（GLUT框架）
// 10. AndroidFrame（Android框架）
// 11. LinuxFrame（Linux框架）
// 12. MacintoshFrame（Macintosh框架）
// 13. ConsoleFrame（控制台框架）

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h" 

#ifndef BUILDING_FRAMEWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_STATIC
 
	namespace Framework
	{
		void StaticDllLib() noexcept
		{
			
		}
	}

#endif // !BUILDING_FRAMEWORK_STATIC