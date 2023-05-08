///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 11:00)

#include "Network/NetworkExport.h"

#include "ConfigurationSubStrategy.h"
#include "Detail/ConfigurationSubStrategyImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::ConfigurationSubStrategy Network::ConfigurationSubStrategy::Create()
{
    return ConfigurationSubStrategy{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationSubStrategy::ConfigurationSubStrategy(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationSubStrategy)

void Network::ConfigurationSubStrategy::Insert(WrappersSubStrategy wrappersSubStrategy, int value)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(wrappersSubStrategy, value);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationSubStrategy, IsExist, WrappersSubStrategy, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationSubStrategy, GetValue, WrappersSubStrategy, int)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ConfigurationSubStrategy)