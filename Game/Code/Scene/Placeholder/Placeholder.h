// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:15)

#ifndef SCENE_PLACEHOLDER_PLACEHOLDER_H
#define SCENE_PLACEHOLDER_PLACEHOLDER_H

#include "Scene/SceneDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace Scene
{
	 class SCENE_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // SCENE_PLACEHOLDER_PLACEHOLDER_H
