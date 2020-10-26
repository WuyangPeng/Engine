//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 16:47)

#include "CoreTools/CoreToolsExport.h"

#include "CommandLineInformation.h"
#include "Detail/CommandLineInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, CommandLineInformation)

CoreTools::CommandLineInformation::CommandLineInformation(int argumentsNumber, char** arguments)
    : m_Impl{ make_shared<ImplType>(argumentsNumber, arguments) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandLineInformation::CommandLineInformation(const char* commandLine)
    : m_Impl{ make_shared<ImplType>(commandLine) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CommandLineInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, ExcessArguments, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, GetExcessArgumentsCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetBoolean, string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetInteger, string, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetFloat, string, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetDouble, string, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, GetString, string, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, GetFileName, const string)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CommandLineInformation, SetUsed, string, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandLineInformation, SetFileNmaeUsed, void)
