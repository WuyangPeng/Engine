// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.4.0.0 (2020/07/15 14:34)

// 动画库（Animation）位于引擎的第五层，
// 只允许调用引擎中的CoreTools、Mathematics、Rendering库，并使用boost工具库。

// 动画库包含以下模块：
// 1.  Helper（帮助）
// 2.  Sprite（精灵动画）
// 3.  Texture（纹理动画）
// 4.  RigidBodyHierarchy（刚体层次结构动画）
// 5.  Skeleton（骨骼动画）
// 6.  PerVertex（每顶点动画）
// 7.  MorphTarget（变形目标动画）
// 8.  Gradient（渐变动画）
// 9.  AnimationManager（动画管理器）

#include "Animation/AnimationExport.h"

#include "Animation/Animation.h"

#ifndef BUILDING_ANIMATION_STATIC

	#include "DllLib.h"

#else // BUILDING_ANIMATION_STATIC

	namespace Animation
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_ANIMATION_STATIC