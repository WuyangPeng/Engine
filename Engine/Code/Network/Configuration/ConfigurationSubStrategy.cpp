///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:57)

#include "Network/NetworkExport.h"

#include "ConfigurationSubStrategy.h"
#include "Detail/ConfigurationSubStrategyImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Network::ConfigurationSubStrategy Network::ConfigurationSubStrategy::Create()
{
    return ConfigurationSubStrategy{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationSubStrategy::ConfigurationSubStrategy(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
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