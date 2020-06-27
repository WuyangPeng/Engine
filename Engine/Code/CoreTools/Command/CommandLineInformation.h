// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:55)

// 命令行信息。
#ifndef CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
#define CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CommandLineInformationImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CommandLineInformation
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(CommandLineInformation);

	public:
		CommandLineInformation(int argumentsNumber, char** arguments);
		explicit CommandLineInformation(const char* commandLine);

		CLASS_INVARIANT_DECLARE;

		// 返回第一个未处理参数的名字。		
		const std::string ExcessArguments() const;
		int GetExcessArgumentsCount() const;

		// 返回存在的选项
		bool GetBoolean(const std::string& name) const;

		int GetInteger(const std::string& name) const;
		float GetFloat(const std::string& name) const;
		double GetDouble(const std::string& name) const;
		const std::string GetString(const std::string& name) const;
		const std::string GetFileName() const;

		void SetUsed(const std::string& argumentsName);
		void SetFileNmaeUsed();

	private:
		IMPL_TYPE_DECLARE(CommandLineInformation);
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
