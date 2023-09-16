///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:36)

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
