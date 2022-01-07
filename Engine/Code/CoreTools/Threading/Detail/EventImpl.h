///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:15)

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
        EventImpl(EventImpl&& rhs) noexcept;
        EventImpl& operator=(EventImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetEvent();
        void ResetEvent();
        void Wait();

    private:
        EventHandle handle;
    };
}

#endif  // CORE_TOOLS_THREADING_EVENT_IMPL_H
