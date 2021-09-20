// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BufferSourceTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferSourceTesting);

    private:
        using FileBufferPtr = std::shared_ptr<FileBuffer>;

    private:
        // 		FileBufferPtr CreateBoolTarget();
        // 		FileBufferPtr CreateStringTarget();
        // 		FileBufferPtr CreateFloatTarget();
        // 		FileBufferPtr CreateEnumTarget();
        // 		FileBufferPtr CreateObjectPointerTarget();
        //
        // 		void VerificationBoolSource(const FileBufferPtr& ptr);
        // 		void VerificationStringSource(const FileBufferPtr& ptr);
        // 		void VerificationFloatSource(const FileBufferPtr& ptr);
        // 		void VerificationEnumSource(const FileBufferPtr& ptr);
        // 		void VerificationObjectPointerSource(const FileBufferPtr& ptr);
        //
        void MainTest() noexcept;
        // 		void ReadBoolTest();
        // 		void ReadStringTest();
        // 		void ReadFloatTest();
        // 		void ReadEnumTest();
        // 		void ReadObjectPointerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H