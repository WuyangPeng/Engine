///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:24)

#include "Network/NetworkExport.h"

#include "HandleSetIteratorImpl.h"

#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorImpl)

Network::ACEHandleType Network::HandleSetIteratorImpl::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ʧ�ܣ�"s))
}
