// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 15:21)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariableImpl.h"
#include "System/FileManager/EnvironmentVariable.h"
#include "System/Helper/PragmaWarning/PropertyTree.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"

using std::string;

CoreTools::EnvironmentVariableImpl
	::EnvironmentVariableImpl(const String& variableName)
	:m_EnvironmentVariable{ nullptr }, m_EnvironmentVariableFromJson{}
{
	GainEnv(variableName);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::EnvironmentVariableImpl
	::GainEnv(const String& variableName)
{
	if (!System::GetEnvironment(variableName, m_EnvironmentVariable) || m_EnvironmentVariable == nullptr)
	{
		// Mac OS X Lion���κ�getenv�ĵ��ý�����nullptr��������ɽ��������⡣
		boost::property_tree::basic_ptree<String, String> mainTree{};

		read_json("Configuration/EnvironmentVariable.json", mainTree);

		m_EnvironmentVariableFromJson = mainTree.get<String>(variableName);
	}
}

CoreTools::EnvironmentVariableImpl
	::~EnvironmentVariableImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	if (m_EnvironmentVariable != nullptr)
	{
		System::FreeEnvironment(m_EnvironmentVariable);
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentVariableImpl)

System::String CoreTools::EnvironmentVariableImpl
	::GetVariable() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (m_EnvironmentVariable != nullptr)
		return m_EnvironmentVariable;
	else
		return m_EnvironmentVariableFromJson;
}
