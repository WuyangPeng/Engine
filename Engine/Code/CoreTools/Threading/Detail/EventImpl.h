///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/08/31 22:50)

#ifndef CORE_TOOLS_THREADING_EVENT_IMPL_H
#define CORE_TOOLS_THREADING_EVENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Windows/Using/WindowsUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EventImpl final
    {
    public:
        using ClassType = EventImpl;
        using EventHandle = System::WindowsHandle;

    public:
        EventImpl(bool manualReset, bool initialState);
        ~EventImpl() noexcept;
        EventImpl(const EventImpl& rhs) = delete;
        EventImpl& operator=(const EventImpl& rhs) = delete;
        EventImpl(EventImpl&& rhs) noexcept = delete;
        EventImpl& operator=(EventImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void SetEvent();
        void ResetEvent();
        void Wait();

    private:
        EventHandle handle;
    };
}

#endif  // CORE_TOOLS_THREADING_EVENT_IMPL_H
