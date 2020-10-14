//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:49)

// 格式化Windows错误消息外部接口类
#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(FormatErrorMessageImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FormatErrorMessage final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(FormatErrorMessage);

        using WindowError = System::WindowError;
        using String = System::String;

    public:
        explicit FormatErrorMessage(WindowError lastError);

        CLASS_INVARIANT_DECLARE;

       [[nodiscard]] const String GetErrorMessage() const;

    private:
        IMPL_TYPE_DECLARE(FormatErrorMessage);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H