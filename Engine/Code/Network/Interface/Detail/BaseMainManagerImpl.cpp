//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 11:11)

#include "Network/NetworkExport.h"

#include "BaseMainManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BaseMainManagerImpl::BaseMainManagerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerImpl)

Network::IOContextType& Network::BaseMainManagerImpl::GetIOContext()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"s));
}

void Network::BaseMainManagerImpl::StopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"s));
}

bool Network::BaseMainManagerImpl::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"s));
}

void Network::BaseMainManagerImpl::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost�����࣡"s));
}
