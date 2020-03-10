// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 12:39)

#include "Network/NetworkExport.h" 

#include "ConfigurationSubStrategy.h"
#include "Detail/ConfigurationSubStrategyImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_shared;

Network::ConfigurationSubStrategy
	::ConfigurationSubStrategy()
	:m_Impl{ make_shared<ImplType>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, ConfigurationSubStrategy)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, ConfigurationSubStrategy)
DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, ConfigurationSubStrategy)

void Network::ConfigurationSubStrategy
	::Insert(WrappersSubStrategy wrappersSubStrategy, int value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(wrappersSubStrategy, value);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationSubStrategy, IsExist, WrappersSubStrategy, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationSubStrategy, GetValue, WrappersSubStrategy, int)


