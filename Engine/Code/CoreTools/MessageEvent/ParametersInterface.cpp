//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:49)

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
