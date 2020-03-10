// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:16)

#include "CoreTools/CoreToolsExport.h"

#include "CommandLineInformation.h"
#include "Detail/CommandLineInformationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::pair;
using std::string;
using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, CommandLineInformation)

CoreTools::CommandLineInformation
	::CommandLineInformation(int argumentsNumber, char** arguments)
	:m_Impl{ make_shared<ImplType>(argumentsNumber,arguments) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandLineInformation
	::CommandLineInformation(char* commandLine)
	:m_Impl{ make_shared<ImplType>(commandLine) }
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

 