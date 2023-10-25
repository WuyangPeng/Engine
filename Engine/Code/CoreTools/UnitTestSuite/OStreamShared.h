///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 13:48)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_SHARED_H
#define CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/SharedExportMacro.h"

#include <string>

CORE_TOOLS_SHARED_EXPORT_IMPL(OStreamImpl);

namespace CoreTools
{
    // 共享类
    class CORE_TOOLS_DEFAULT_DECLARE OStreamShared final
    {
    public:
        using OStreamSharedImpl = OStreamImpl;
        SHARED_TYPE_DECLARE(OStreamShared);

    public:
        explicit OStreamShared(bool isCout);
        explicit OStreamShared(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        template <typename T>
        OStreamShared& operator<<(const T& value);

        NODISCARD std::ostream& GetStream() noexcept;

        NODISCARD bool IsCout() const noexcept;
        NODISCARD bool IsCerr() const noexcept;
        NODISCARD bool IsFile() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_O_STREAM_SHARED_H
