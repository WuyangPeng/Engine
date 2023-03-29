///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:11)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(LogFileNameImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogFileName final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(LogFileName);
        using String = System::String;

    public:
        explicit LogFileName(const System::TChar* fileName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileName() const;

    private:
        PackageType::ConstSharedPtr impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
