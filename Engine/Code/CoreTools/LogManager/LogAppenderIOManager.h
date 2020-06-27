// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:06)

// ��־���λ��IO�����������ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

#include <boost/noncopyable.hpp>

#include <boost/format/format_fwd.hpp>

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogAppenderIOManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogAppenderIOManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(LogAppenderIOManager);
		using AppenderManagerPtr = std::shared_ptr<AppenderManager>;
		using Format = boost::basic_format<System::TChar>;

	public:
		LogAppenderIOManager(LogLevel logLevel, const AppenderManagerPtr& appenderManager);
		LogAppenderIOManager();

		CLASS_INVARIANT_DECLARE;

		// ����������ͨ����ӡ��־����������º������׳��κ��쳣����Ҫ���������쳣��
		LogAppenderIOManager& operator << (const char* message) noexcept;
		LogAppenderIOManager& operator << (const wchar_t* message) noexcept;
		LogAppenderIOManager& operator << (int32_t value) noexcept;
		LogAppenderIOManager& operator << (uint32_t value) noexcept;
		LogAppenderIOManager& operator << (int64_t value) noexcept;
		LogAppenderIOManager& operator << (uint64_t value) noexcept;
		LogAppenderIOManager& operator << (float value) noexcept;
		LogAppenderIOManager& operator << (double value) noexcept;
		LogAppenderIOManager& operator << (const std::string& message) noexcept;
		LogAppenderIOManager& operator << (const std::wstring& message) noexcept;
		LogAppenderIOManager& operator << (const FunctionDescribed& functionDescribed) noexcept;
		LogAppenderIOManager& operator << (const Error& error) noexcept;
		LogAppenderIOManager& operator << (LogFilter filterType) noexcept;
		LogAppenderIOManager& operator << (LogAppenderIOManageSign sign) noexcept;
		LogAppenderIOManager& operator << (const LogFileName& logFileName) noexcept;

		void SetAppenderManager(const AppenderManagerPtr& appenderManager);

	private:
		IMPL_TYPE_DECLARE(LogAppenderIOManager);
		Mutex m_LogAppenderIOManagerMutex;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
