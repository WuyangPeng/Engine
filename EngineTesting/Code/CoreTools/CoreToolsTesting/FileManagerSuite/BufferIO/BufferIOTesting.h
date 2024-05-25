/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 21:50)

#ifndef CORE_TOOLS_TESTING_BUFFER_IO_TESTING_H
#define CORE_TOOLS_TESTING_BUFFER_IO_TESTING_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BufferIOTesting : public UnitTest
    {
    public:
        using ClassType = BufferIOTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit BufferIOTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;

    protected:
        NODISCARD static std::string GetBufferIOContent();
        NODISCARD static size_t GetBufferIOContentSize() noexcept;
        NODISCARD static int GetBufferSize();

    private:
        static const std::string bufferIOContent;
    };
}

#endif  // CORE_TOOLS_TESTING_BUFFER_IO_TESTING_H