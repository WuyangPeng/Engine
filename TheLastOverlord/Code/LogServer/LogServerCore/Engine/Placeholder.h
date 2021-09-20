// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 22:53)

#ifndef LOG_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LOG_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LogServer/LogServerCore/LogServerCoreDll.h"

#include "LogServer/LogServerCore/Macro/ExportMacro.h"  

namespace LogServerCore
{
	class LOG_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // LOG_SERVER_CORE_ENGINE_PLACEHOLDER_H
