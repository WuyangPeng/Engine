///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 14:33)

#include "PropertiesFriend.h"
#include "PropertiesFriendTemplateDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::PropertiesFriend::PropertiesFriend() noexcept
    : templateType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertiesFriend)

int CoreTools::PropertiesFriend::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return templateType.value;
}
