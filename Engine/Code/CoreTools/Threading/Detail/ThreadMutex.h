///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 13:03)

#ifndef CORE_TOOLS_THREADING_THREAN_MUTEX_H
#define CORE_TOOLS_THREADING_THREAN_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/MutexUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadMutex final : public MutexImpl
    {
    public:
        using ClassType = ThreadMutex;
        using ParentType = MutexImpl;
        using MutexType = System::MutexType;

    public:
        ThreadMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() final;
        void Delete() noexcept final;
        void Enter() final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        MutexType mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAN_MUTEX_H
