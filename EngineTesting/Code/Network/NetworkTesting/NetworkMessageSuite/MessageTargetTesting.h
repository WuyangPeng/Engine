// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:49)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkMessage/MessageSource.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <array>
#include <vector>

namespace Network
{
    class MessageTargetTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MessageTargetTesting);
        using TestingType = MessageTarget;

    private:
        void MainTest() noexcept;

        void SourceTest(ParserStrategy parserStrategy);

        MessageBufferSharedPtr CreateTargetMessageBuffer(ParserStrategy parserStrategy);

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
        static constexpr auto sm_BoolArraySize = 10;
        static constexpr auto sm_EnumArraySize = 11;
        static constexpr auto sm_Int16ArraySize = 12;
        static constexpr auto sm_StringArraySize = 13;
        static constexpr auto sm_Int32VectorSize = 14;
        static constexpr auto sm_StringVectorSize = 15;

        static constexpr bool sm_BoolValue{ true };
        static constexpr int16_t sm_Int16Value{ 10 };
        static constexpr int16_t sm_Int32Value{ 15 };
        static const std::string sm_StringValue;

        const std::array<bool, sm_BoolArraySize> m_BoolBuffer1;
        const std::array<bool, sm_BoolArraySize> m_BoolBuffer2;
        const std::array<ParserStrategy, sm_EnumArraySize> m_ParserStrategyBuffer1;
        const std::array<ParserStrategy, sm_EnumArraySize> m_ParserStrategyBuffer2;
        const std::array<int16_t, sm_Int16ArraySize> m_Int16Buffer1;
        const std::array<int16_t, sm_Int16ArraySize> m_Int16Buffer2;
        const std::array<std::string, sm_StringArraySize> m_StringBuffer1;
        const std::array<std::string, sm_StringArraySize> m_StringBuffer2;
        const std::vector<int32_t> m_Int32Vector;
        const std::vector<std::string> m_StringVector;
        int m_BytesWrite;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TARGET_TESTING_H