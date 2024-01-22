/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:11)

#ifndef CORE_TOOLS_THREADING_EVENT_H
#define CORE_TOOLS_THREADING_EVENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EventImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Event final
    {
    public:
        NON_COPY_TYPE_DECLARE(Event);

    public:
        Event(bool manualReset, bool initialState);
        ~Event() noexcept = default;
        Event(const Event& rhs) noexcept = delete;
        Event& operator=(const Event& rhs) noexcept = delete;
        Event(Event&& rhs) noexcept = delete;
        Event& operator=(Event&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void SetEvent();
        void ResetEvent();
        void Wait();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_EVENT_H
