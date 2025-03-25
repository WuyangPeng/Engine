/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:20)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <iostream>
#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OStreamImpl final
    {
    public:
        using ClassType = OStreamImpl;

    public:
        explicit OStreamImpl(bool isCout) noexcept;
        explicit OStreamImpl(const std::string& fileName);

        ~OStreamImpl() noexcept = default;
        OStreamImpl(const OStreamImpl& rhs) = delete;
        OStreamImpl& operator=(const OStreamImpl& rhs) = delete;
        OStreamImpl(OStreamImpl&& rhs) noexcept;
        OStreamImpl& operator=(OStreamImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::ostream& GetStream() noexcept;

        NODISCARD bool IsCout() const noexcept;
        NODISCARD bool IsCerr() const noexcept;
        NODISCARD bool IsFile() const noexcept;

    private:
        using OStreamSharedPtr = std::shared_ptr<std::ostream>;

    private:
        OStreamSharedPtr stream;
        bool isCout;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_IMPL_H
