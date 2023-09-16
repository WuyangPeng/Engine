///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:35)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_JSON_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_JSON_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestJsonMessage final
    {
    public:
        using ClassType = TestJsonMessage;

    public:
        explicit TestJsonMessage(const std::string& message);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetJsonMessage() const;

    private:
        std::string message;
    };

}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_JSON_MESSAGE_H
