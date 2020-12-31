//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:45)

#include "CoreTools/CoreToolsExport.h"

#include "CallbackParametersImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CallbackParametersImpl::CallbackParametersImpl(int count)
    : m_Container(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CallbackParametersImpl)

int CoreTools::CallbackParametersImpl::GetContainerSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Container.size());
}
