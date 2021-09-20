//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 11:32)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/SharedExportMacro.h"

CORE_TOOLS_SHARED_EXPORT_IMPL(OStreamImpl);

#include <iostream>
#include <string>

namespace CoreTools
{
    // ������
    class CORE_TOOLS_DEFAULT_DECLARE OStreamShared final
    {
    public:
        using OStreamSharedImpl = OStreamImpl;
        SHARED_TYPE_DECLARE(OStreamShared);

    public:
        OStreamShared();
        explicit OStreamShared(bool isCout);
        explicit OStreamShared(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        template <typename T>
        OStreamShared& operator<<(const T& value);

        [[nodiscard]] std::ostream& GetStream() noexcept;

        [[nodiscard]] bool IsCout() const noexcept;
        [[nodiscard]] bool IsCerr() const noexcept;
        [[nodiscard]] bool IsFile() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
