// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
	enum class MD5ContextStatus
	{
		Init,
		Update,
		Final,
		Disabled,
	};
}
#endif // CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H
