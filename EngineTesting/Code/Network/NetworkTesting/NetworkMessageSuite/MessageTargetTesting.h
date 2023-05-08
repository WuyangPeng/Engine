///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:25)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkMessage/MessageSource.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <array>
#include <vector>

namespace Network
{
    class MessageTargetTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageTargetTesting;
        using ParentType = UnitTest;
        using TestingType = MessageTarget;

    public:
        explicit MessageTargetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void SourceTest(ParserStrategy parserStrategy);

        NODISCARD MessageBufferSharedPtr CreateTargetMessageBuffer(ParserStrategy parserStrategy);

        void MessageTargetWriteBool(MessageTarget& messageTarget);
        void MessageTargetWriteEnum(MessageTarget& messageTarget, ParserStrategy parserStrategy);
        void MessageTargetWriteInt16(MessageTarget& messageTarget);
        void MessageTargetWriteString(MessageTarget& messageTarget);
        void MessageTargetWriteVector(MessageTarget& messageTarget);

        void VerificationBool(MessageSource& messageSource);
        void VerificationEnum(ParserStrategy parserStrategy, MessageSource& messageSource);
        void VerificationInt16(MessageSource& messageSource);
        void VerificationString(MessageSource& messageSource);
        void VerificationVector(MessageSource& messageSource);

        void DoRunUnitTest() override;

    private:
        static constexpr auto boolArraySize = 10;
        static constexpr auto enumArraySize = 11;
        static constexpr auto int16ArraySize = 12;
        static constexpr auto stringArraySize = 13;
        static constexpr auto int32VectorSize = 14;
        static constexpr auto stringVectorSize = 15;

        static constexpr bool boolValue{ true };
        static constexpr int16_t int16Value{ 10 };
        static constexpr int16_t int32Value{ 15 };
        static const std::string stringValue;

        const std::array<bool, boolArraySize> boolBuffer1;
        const std::array<bool, boolArraySize> boolBuffer2;
        const std::array<ParserStrategy, enumArraySize> parserStrategyBuffer1;
        const std::array<ParserStrategy, enumArraySize> parserStrategyBuffer2;
        const std::array<int16_t, int16ArraySize> int16Buffer1;
        const std::array<int16_t, int16ArraySize> int16Buffer2;
        const std::array<std::string, stringArraySize> stringBuffer1;
        const std::array<std::string, stringArraySize> stringBuffer2;
        const std::vector<int32_t> int32Vector;
        const std::vector<std::string> stringVector;
        int bytesWrite;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H