// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 09:45)

// 动画库（Animation）位于引擎的第五层，
// 只允许调用引擎中的CoreTools、Mathematics、Rendering库，并使用boost和stlsoft工具库。

// 动画库包含以下模块：
// 1.  Macro（宏）
// 2.  ConsoleGraph（控制台图形）
// 3.  ElfAnimation（精灵动画）
// 4.  TextureAnimation（纹理动画）
// 5.  RigidBodyHierarchyAnimation（刚体层次结构动画）
// 6.  SkeletonAnimation（骨骼动画）
// 7.  PerVertexAnimation（每顶点动画）
// 8.  MorphTargetAnimation（变形目标动画）
// 9.  GradientAnimation（渐变动画）
// 10. AnimationManager（动画管理器）

#include "Animation/AnimationExport.h"

#include "Animation/Animation.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"

#ifndef BUILDING_ANIMATION_STATIC

	#include "DllLib.h"

#else // BUILDING_ANIMATION_STATIC

	namespace Animation
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ANIMATION_STATIC