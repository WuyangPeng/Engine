///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 16:23)

#include "TestJsonMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::TestJsonMessage::TestJsonMessage(const std::string& message)
    : message{ message }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, TestJsonMessage)

std::string Network::TestJsonMessage::GetJsonMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message;
};
