///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 14:07)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariable.h"
#include "Detail/EnvironmentVariableImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::EnvironmentVariable::EnvironmentVariable(const String& variableName)
    : impl{ variableName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentVariable)

CoreTools::EnvironmentVariable::String CoreTools::EnvironmentVariable::GetVariable() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetVariable();
}
