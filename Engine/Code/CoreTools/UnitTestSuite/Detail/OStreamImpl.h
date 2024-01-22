/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:22)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <iostream>
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
