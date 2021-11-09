///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:46)

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
