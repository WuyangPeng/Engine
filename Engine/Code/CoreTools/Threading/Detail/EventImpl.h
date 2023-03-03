///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:16)

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
