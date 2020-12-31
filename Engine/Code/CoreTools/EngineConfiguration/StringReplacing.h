//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 11:19)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(StringReplacingImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE StringReplacing final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StringReplacing);
        using String = System::String;

    public:
        explicit StringReplacing(const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const String GetReplacing(const String& original) const;

    private:
        IMPL_TYPE_DECLARE(StringReplacing);
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
