///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/08/31 17:00)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include "System/Helper/PragmaWarning/Mutex.h"

namespace CoreTools
{
    // boost���ǲ��ɵݹ�ġ�������������������׳��쳣��
    class CORE_TOOLS_HIDDEN_DECLARE BoostMutex final : public MutexImpl
    {
    public:
        using ClassType = BoostMutex;
        using ParentType = MutexImpl;

    public:
        BoostMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        boost::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_MUTEX_H