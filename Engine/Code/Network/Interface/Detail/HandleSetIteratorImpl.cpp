//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 11:23)

#include "Network/NetworkExport.h"

#include "HandleSetIteratorImpl.h"

#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorImpl)

Network::ACEHandle Network::HandleSetIteratorImpl::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ʧ�ܣ�"s));
}
