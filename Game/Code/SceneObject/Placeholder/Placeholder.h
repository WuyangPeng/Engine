// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:29)

#ifndef SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H
#define SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H

#include "SceneObject/SceneObjectDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace SceneObject
{
	 class SCENE_OBJECT_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // SCENE_OBJECT_PLACEHOLDER_PLACEHOLDER_H
