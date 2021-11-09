///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 14:09)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariableImpl.h"
#include "System/FileManager/EnvironmentVariable.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

CoreTools::EnvironmentVariableImpl::EnvironmentVariableImpl(const String& variableName)
    : environmentVariable{ nullptr }, environmentVariableFromJson{}
{
    GainEnv(variableName);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::EnvironmentVariableImpl::GainEnv(const String& variableName)
{
    if (!System::GetEnvironment(variableName, environmentVariable) || environmentVariable == nullptr)
    {
        // Mac OS X Lion的任何getenv的调用将返回nullptr。这个技巧解决这个问题。
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
