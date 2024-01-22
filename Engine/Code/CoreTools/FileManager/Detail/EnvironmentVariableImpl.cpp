/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:03)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariableImpl.h"
#include "System/FileManager/EnvironmentVariable.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::EnvironmentVariableImpl::EnvironmentVariableImpl(const String& variableName)
    : environmentVariable{ nullptr }, environmentVariableFromJson{}
{
    GainEnv(variableName);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::EnvironmentVariableImpl::GainEnv(const String& variableName)
{
    if (!System::GetEnvironment(variableName, environmentVariable) || environmentVariable == nullptr)
    {
        // Mac OS X Lion���κ�getenv�ĵ��ý�����nullptr��������ɽ��������⡣
        boost::property_tree::basic_ptree<String, String> mainTree{};

        read_json("Configuration/EnvironmentVariable.json", mainTree);

        environmentVariableFromJson = mainTree.get<String>(variableName);
    }
}

CoreTools::EnvironmentVariableImpl::~EnvironmentVariableImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (environmentVariable != nullptr)
    {
        System::FreeEnvironment(environmentVariable);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentVariableImpl)

System::String CoreTools::EnvironmentVariableImpl::GetVariable() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (environmentVariable != nullptr)
        return environmentVariable;
    else
        return environmentVariableFromJson;
}
