///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 13:04)

#ifndef CORE_TOOLS_THREADING_WINDOWS_MUTEX_H
#define CORE_TOOLS_THREADING_WINDOWS_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/MutexUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WindowsMutex final : public MutexImpl
    {
    public:
        using ClassType = WindowsMutex;
        using ParentType = MutexImpl;
        using MutexHandle = System::WindowsHandle;

    public:
        WindowsMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() final;
        void Delete() noexcept final;
        void Enter() final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        MutexHandle mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_WINDOWS_MUTEX_H