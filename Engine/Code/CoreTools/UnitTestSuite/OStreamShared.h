///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 19:00)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/SharedExportMacro.h"

#include <iostream>
#include <string>

CORE_TOOLS_SHARED_EXPORT_IMPL(OStreamImpl);

namespace CoreTools
{
    // ������
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

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
