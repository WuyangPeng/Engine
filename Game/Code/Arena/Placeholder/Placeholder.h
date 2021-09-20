// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 20:43)

#ifndef ARENA_PLACEHOLDER_PLACEHOLDER_H
#define ARENA_PLACEHOLDER_PLACEHOLDER_H

#include "Arena/ArenaDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace Arena
{
	 class ARENA_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // ARENA_PLACEHOLDER_PLACEHOLDER_H
