// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:02)

// ���λ�ã�����̨��
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AppenderConsole : public AppenderImpl
	{
	public:
		using ClassType = AppenderConsole;
		using ParentType = AppenderImpl;

	public:
		explicit AppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		AppenderType GetAppenderType() const noexcept override;

		const AppenderImplPtr Clone() const override;

	private:
		void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H
