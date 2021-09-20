// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/04 21:30)

#ifndef CHARACTER_INFORMATION_PLACEHOLDER_PLACEHOLDER_H
#define CHARACTER_INFORMATION_PLACEHOLDER_PLACEHOLDER_H

#include "CharacterInformation/CharacterInformationDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace CharacterInformation
{
	 class CHARACTER_INFORMATION_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // CHARACTER_INFORMATION_PLACEHOLDER_PLACEHOLDER_H
