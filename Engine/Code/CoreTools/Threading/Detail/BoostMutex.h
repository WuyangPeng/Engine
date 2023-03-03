///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 16:13)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include "System/Helper/PragmaWarning/Mutex.h"

// boost���ǲ��ɵݹ�ġ�������������������׳��쳣��
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BoostMutex final : public MutexImpl
    {
    public:
        using ClassType = BoostMutex;
        using ParentType = MutexImpl;

    public:
        BoostMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        boost::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_MUTEX_H