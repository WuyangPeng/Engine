//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:49)

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
        ~EventImpl();
        EventImpl(const EventImpl&) = delete;
        EventImpl& operator=(const EventImpl&) = delete;
        EventImpl(EventImpl&&) noexcept = delete;
        EventImpl& operator=(EventImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void SetEvent();
        void ResetEvent();
        void Wait();

    private:
        EventHandle m_Handle;
    };
}

#endif  // CORE_TOOLS_THREADING_EVENT_IMPL_H
