/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:10)

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

        void SetEvent() const;
        void ResetEvent() const;
        void Wait() const;

    private:
        EventHandle handle;
    };
}

#endif  // CORE_TOOLS_THREADING_EVENT_IMPL_H
