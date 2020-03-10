// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:38)

// 框架库（Framework）位于引擎的最上层，
// 封装了与操作系统相关的特定需求（包括Windows、Linux、Android和Macintosh）
// 允许调用引擎中的所有库，并使用boost和stlsoft工具库。

// 框架库包含以下模块：
// 1.  Macro（宏）
// 2.  MainFunctionHelper（主函数帮助）
// 3.  WindowCreate（窗口创建）
// 4.  WindowProcess（窗口进程）
// 5.  WindowRegister（窗口注册）
// 6.  Application（应用）
// 7.  MiddleLayer（中间层）
// 8.  WindowsAPIFrame（WindowsAPI框架）
// 9.  OpenGLGlutFrame（Glut框架）
// 10. AndroidFrame（Android框架）
// 11. LinuxFrame（Linux框架）
// 12. MacintoshFrame（Macintosh框架）

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h" 

#include "System/SystemLib.h"

#include "CoreTools/CoreToolsLib.h"

#include "Network/NetworkLib.h"
#include "Database/DatabaseLib.h"
#include "Script/ScriptLib.h"	
#include "Mathematics/MathematicsLib.h"	
#include "SoundEffect/SoundEffectLib.h"		
#include "InputOutput/InputOutputLib.h"		

#include "ResourceManager/ResourceManagerLib.h"		
#include "Rendering/RenderingLib.h"		
#include "Physics/PhysicsLib.h"		
#include "Imagics/ImagicsLib.h"		

#include "Animation/AnimationLib.h"		
#include "ArtificialIntellegence/ArtificialIntellegenceLib.h"		
#include "UserInterface/UserInterfaceLib.h"	

#include "AssistTools/AssistToolsLib.h"	

#ifndef BUILDING_FRAMEWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_STATIC

	namespace Framework
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FRAMEWORK_STATIC