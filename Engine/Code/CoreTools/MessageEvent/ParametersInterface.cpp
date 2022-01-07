///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/26 18:33)

#include "CoreTools/CoreToolsExport.h"

#include "ParametersInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ParametersInterface)

const CoreTools::ParametersInterface::BaseSharedPtr CoreTools::ParametersInterface::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
