/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:30)

#include "Network/NetworkExport.h"

#include "HandleSetImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetImpl)

bool Network::HandleSetImpl::IsFdSetCountIsOne() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return IsFdSetCount() == 1;
}
