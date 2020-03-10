// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:54)

// ��������Ϣ��
#ifndef CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H
#define CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
	class CommandArgumentContainer;

	class CORE_TOOLS_HIDDEN_DECLARE CommandLineInformationImpl
	{
	public:
		using ClassType = CommandLineInformationImpl;

	public:
		CommandLineInformationImpl(int argumentsNumber, char** arguments);
		explicit CommandLineInformationImpl(char* commandLine);
		~CommandLineInformationImpl();

		CLASS_INVARIANT_DECLARE;

		// ���ص�һ��δ������������֡�		
		const std::string ExcessArguments() const;
		int GetExcessArgumentsCount() const;

		bool GetBoolean(const std::string& name) const; // ���ش��ڵ�ѡ��

		int GetInteger(const std::string& name) const;
		float GetFloat(const std::string& name) const;
		double GetDouble(const std::string& name) const;
		const std::string GetString(const std::string& name) const;
		const std::string GetFileName() const;

		void SetUsed(const std::string& argumentsName);
		void SetFileNmaeUsed();

	private:
		using CommandArgumentContainerSharedPtr = std::shared_ptr<CommandArgumentContainer>;

	private:
		static const std::string sm_FileName;

		CommandArgumentContainerSharedPtr m_CommandArgumentContainer;
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H
