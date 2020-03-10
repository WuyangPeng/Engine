// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:40)

// ��ȡ�ַ�����Ӧ�Ļ���������
#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <boost/noncopyable.hpp>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE EnvironmentVariableImpl : private boost::noncopyable
	{
	public:
		using ClassType = EnvironmentVariableImpl;
		using TChar = System::TChar;
		using String = System::String;		

	public:
		explicit EnvironmentVariableImpl(const String& variableName);
		~EnvironmentVariableImpl();

		CLASS_INVARIANT_DECLARE;

		String GetVariable() const;

	private:
		void GainEnv(const String& variableName);

	private:
		TChar* m_EnvironmentVariable;
		String m_EnvironmentVariableFromJson;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
