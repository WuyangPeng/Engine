///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariable.h"
#include "Detail/EnvironmentVariableImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::EnvironmentVariable::EnvironmentVariable(const String& variableName)
    : impl{ variableName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentVariable)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, EnvironmentVariable, GetVariable, System::String);
