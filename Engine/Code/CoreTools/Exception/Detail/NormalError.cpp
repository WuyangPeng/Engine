///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 15:15)

#include "CoreTools/CoreToolsExport.h"

#include "NormalError.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NormalError::NormalError(const FunctionDescribed& functionDescribed, const String& message)
    : ParentType{ functionDescribed, message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NormalError)
