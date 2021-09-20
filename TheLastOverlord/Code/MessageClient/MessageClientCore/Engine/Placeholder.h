// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:27)

#ifndef MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "MessageClient/MessageClientCore/MessageClientCoreDll.h"

#include "MessageClient/MessageClientCore/Macro/ExportMacro.h"  

namespace MessageClientCore
{
	class MESSAGE_CLIENT_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // MESSAGE_CLIENT_CORE_ENGINE_PLACEHOLDER_H
