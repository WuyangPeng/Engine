//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 11:21)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <iostream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OStreamImpl final : private boost::noncopyable
    {
    public:
        using ClassType = OStreamImpl;

    public:
        explicit OStreamImpl(bool isCout) noexcept;
        explicit OStreamImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::ostream& GetStream() noexcept;

        [[nodiscard]] bool IsCout() const noexcept;
        [[nodiscard]] bool IsCerr() const noexcept;
        [[nodiscard]] bool IsFile() const noexcept;

    private:
        using OstreamSharedPtr = std::shared_ptr<std::ostream>;

    private:
        OstreamSharedPtr m_OStream;
        bool m_IsCout;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H
