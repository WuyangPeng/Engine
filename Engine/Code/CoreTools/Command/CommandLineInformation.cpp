///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/21 11:38)

#include "CoreTools/CoreToolsExport.h"

#include "CommandLineInformation.h"
#include "Detail/CommandLineInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::CommandLineInformation::CommandLineInformation(int argumentsNumber, char** arguments)
    : impl{ argumentsNumber, arguments }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommandLineInformation::CommandLineInformation(const char* commandLine)
    : impl{ commandLine }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandLineInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, ExcessArguments, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandLineInformation, GetExcessArgumentsCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetBoolean, std::string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetInteger, std::string, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetFloat, std::string, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetDouble, std::string, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetString, std::string, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, GetFileName, std::string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, SetUsed, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, SetFileNameUsed, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CommandLineInformation)