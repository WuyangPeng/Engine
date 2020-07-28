// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 10:48)

// 辅助工具库（AssistTools）位于引擎的第六层，
// 可以引擎中除了System、Framework的其他库，
// 并使用boost和stlsoft工具库。

// 辅助工具库包含以下模块：
// 1.  Macro（宏）
// 2.  GenerateProjects（生成项目）
// 3.  FeaturesImporter（特征导入）
// 4.  BmpColorToGray（灰态Bmp颜色）
// 5.  BmpToWmtf（Bmp转换Wmtf）
// 6.  WmfxCompiler（Wmfx编译器）

#include "AssistTools/AssistToolsExport.h"

#include "AssistTools/AssistTools.h"

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

#ifndef BUILDING_ASSIST_TOOLS_STATIC

	#include "DllLib.h"

#else // BUILDING_ASSIST_TOOLS_STATIC

	namespace AssistTools
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_ASSIST_TOOLS_STATIC

