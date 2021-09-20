// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 21:13)

#ifndef INSTANCE_PLACEHOLDER_PLACEHOLDER_H
#define INSTANCE_PLACEHOLDER_PLACEHOLDER_H

#include "Instance/InstanceDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace Instance
{
	 class INSTANCE_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // INSTANCE_PLACEHOLDER_PLACEHOLDER_H
