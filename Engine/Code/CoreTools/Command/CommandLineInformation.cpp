///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 13:55)

#include "CoreTools/CoreToolsExport.h"

#include "CommandLineInformation.h"
#include "Detail/CommandLineInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, ExcessArguments, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandLineInformation, GetExcessArgumentsCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetBoolean, string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetInteger, string, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetFloat, string, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetDouble, string, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetString, string, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, GetFileName, string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, SetUsed, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, SetFileNameUsed, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CommandLineInformation)