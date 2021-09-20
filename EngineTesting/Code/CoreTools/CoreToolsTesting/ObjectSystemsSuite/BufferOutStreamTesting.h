// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BufferOutStreamTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferOutStreamTesting);

    private:
        std::string GetTopLevelContent() const;
        std::string GetAligningString(const std::string& original) const;
        std::string GetBoolObjectContent(int uniqueID, const std::string& rttiTypeName) const;
        std::string GetStringObjectContent(int uniqueID, const std::string& rttiTypeName) const;
        std::string GetIntObjectContent(int uniqueID, const std::string& rttiTypeName) const;
        std::string GetEnumObjectContent(int uniqueID, const std::string& rttiTypeName) const;
        std::string GetNullObjectContent(int uniqueID, const std::string& rttiTypeName) const;
        std::string GetPointerObjectContent(int uniqueID, const std::string& rttiTypeName) const;

        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H