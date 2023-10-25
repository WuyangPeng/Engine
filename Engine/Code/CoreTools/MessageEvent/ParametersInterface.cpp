///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:10)

#include "CoreTools/CoreToolsExport.h"

#include "ParametersInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ParametersInterface)

CoreTools::ParametersInterface::BaseSharedPtr CoreTools::ParametersInterface::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
