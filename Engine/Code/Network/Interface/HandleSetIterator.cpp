///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/21 17:02)

#include "Network/NetworkExport.h"

#include "HandleSetIterator.h"
#include "Detail/HandleSetIteratorFactory.h"
#include "Detail/HandleSetIteratorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::HandleSetIterator::HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, handleSet }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIterator)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, HandleSetIterator, operator(), Network::ACEHandle)