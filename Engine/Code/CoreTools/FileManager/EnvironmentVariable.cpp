//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 14:25)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentVariable.h"
#include "Detail/EnvironmentVariableImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::EnvironmentVariable::EnvironmentVariable(const System::String& variableName)
    : impl{  variableName  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentVariable)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, EnvironmentVariable, GetVariable, System::String);
