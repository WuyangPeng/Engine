//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:45)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogFileNameImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogFileName final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogFileName);
        using String = System::String;

    public:
        explicit LogFileName(const System::TChar* fileName) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetFileName() const;

    private:
        IMPL_TYPE_DECLARE(LogFileName);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
