///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 15:02)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_SOURCE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_SOURCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/NetworkMessage/MessageSource.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <array>
#include <vector>

namespace Network
{
    class MessageSourceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageSourceTesting;
        using ParentType = UnitTest;
        using TestingType = MessageSource;

    public:
        explicit MessageSourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SourceTest(ParserStrategy parserStrategy);

        void IncrementBytesProcessedTest(ParserStrategy parserStrategy);

        NODISCARD MessageBufferSharedPtr CreateTargetMessageBuffer(ParserStrategy parserStrategy) const;

        void MessageTargetWriteBool(MessageTarget& messageTarget) const;
        void MessageTargetWriteEnum(MessageTarget& messageTarget, ParserStrategy parserStrategy) const;
        void MessageTargetWriteInt16(MessageTarget& messageTarget) const;
        void MessageTargetWriteString(MessageTarget& messageTarget) const;
        void MessageTargetWriteVector(MessageTarget& messageTarget) const;

        void ReadBoolTest(TestingType& messageSource);
        void ReadEnumTest(ParserStrategy parserStrategy, TestingType& messageSource);
        void ReadInt16Test(TestingType& messageSource);
        void ReadStringTest(TestingType& messageSource);
        void ReadVectorTest(TestingType& messageSource);

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
        int bytesRead;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_SOURCE_TESTING_H