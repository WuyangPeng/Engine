/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "HandleSetIterator.h"
#include "Detail/HandleSetIteratorFactory.h"
#include "Detail/HandleSetIteratorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::HandleSetIterator::HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, handleSet }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIterator)

Network::ACEHandleType Network::HandleSetIterator::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    return (*impl)();
}
