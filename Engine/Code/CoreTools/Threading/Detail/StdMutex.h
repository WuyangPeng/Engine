/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:10)

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
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        void DoLeave() noexcept;

    private:
        std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_MUTEX_H