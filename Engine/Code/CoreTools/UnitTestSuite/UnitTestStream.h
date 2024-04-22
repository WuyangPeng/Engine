/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:23)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "OStreamShared.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestStream
    {
    public:
        using ClassType = UnitTestStream;

    public:
        explicit UnitTestStream(const OStreamShared& streamShared) noexcept;
        virtual ~UnitTestStream() = default;

        UnitTestStream(const UnitTestStream& rhs) = delete;
        UnitTestStream& operator=(const UnitTestStream& rhs) = delete;
        UnitTestStream(UnitTestStream&& rhs) noexcept;
        UnitTestStream& operator=(UnitTestStream&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD OStreamShared& GetStream() noexcept;
        NODISCARD bool IsStreamSharedFile() const noexcept;

    private:
        OStreamShared streamShared;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
