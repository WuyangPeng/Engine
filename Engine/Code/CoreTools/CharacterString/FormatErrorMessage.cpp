///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/27 18:23)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessage.h"
#include "Detail/FormatErrorMessageImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FormatErrorMessage::FormatErrorMessage(WindowError lastError)
    : impl{ lastError }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessage)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FormatErrorMessage, GetErrorMessage, const System::String)
