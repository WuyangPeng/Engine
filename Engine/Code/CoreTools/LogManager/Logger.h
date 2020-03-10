// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:07)

// ��¼�����ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_LOGGER_H
#define CORE_TOOLS_LOG_MANAGER_LOGGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

CORE_TOOLS_EXPORT_SHARED_PTR(LoggerImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Logger
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Logger);

	public:
		Logger(LogFilter logFilter, LogLevel logLevel);

		CLASS_INVARIANT_DECLARE;

		LogFilter GetLogFilterType() const noexcept;
		LogLevel GetLogLevel() const noexcept;

		void SetLogLevel(LogLevel level);

	private:
		IMPL_TYPE_DECLARE(Logger);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOGGER_H
