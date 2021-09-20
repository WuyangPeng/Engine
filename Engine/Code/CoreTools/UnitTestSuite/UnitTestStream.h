//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 13:27)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "OStreamShared.h"

#include <boost/noncopyable.hpp>
#include <iosfwd>



namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestStream
    {
    public:
        using ClassType = UnitTestStream;

    public:
        explicit UnitTestStream(const OStreamShared& streamShared) noexcept;
        virtual ~UnitTestStream() = default;

        UnitTestStream(const UnitTestStream& rhs) = default;
        UnitTestStream& operator=(const UnitTestStream& rhs) = default;
        UnitTestStream(UnitTestStream&& rhs) noexcept = default;
        UnitTestStream& operator=(UnitTestStream&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] OStreamShared& GetStream() noexcept;
        [[nodiscard]] bool IsStreamSharedFile() const noexcept;

    private:
        OStreamShared m_StreamShared;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
