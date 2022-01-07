///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:21)

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
