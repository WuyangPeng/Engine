// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:06)

// 记录器类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H

#include "CoreTools/CoreToolsDll.h" 

#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{ 
	class CORE_TOOLS_HIDDEN_DECLARE LoggerImpl
	{
	public:
		using ClassType = LoggerImpl;

	public:
		LoggerImpl(LogFilter logFilter, LogLevel logLevel);

		CLASS_INVARIANT_DECLARE;

		LogFilter GetLogFilterType() const noexcept;
		LogLevel GetLogLevel() const noexcept;
		void SetLogLevel(LogLevel level) noexcept;

	private:
		LogFilter m_LogFilter;
		LogLevel m_Level;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H
