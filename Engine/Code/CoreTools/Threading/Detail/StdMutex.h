///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 16:24)

#ifndef CORE_TOOLS_THREADING_STD_MUTEX_H
#define CORE_TOOLS_THREADING_STD_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include <mutex>

// ��׼�����ǲ��ɵݹ�ġ�
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StdMutex final : public MutexImpl
    {
    public:
        using ClassType = StdMutex;
        using ParentType = MutexImpl;

    public:
        StdMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() override;
        void Leave() noexcept override;

    private:
        void DoLeave();

    private:
        std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_MUTEX_H