//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 11:52)

#ifndef CORE_TOOLS_THREADING_DLL_MUTEX_H
#define CORE_TOOLS_THREADING_DLL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "Flags/MutexFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(MutexImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DllMutex
    {
    public:
        using DllMutexImpl = MutexImpl;
        NON_COPY_CLASSES_TYPE_DECLARE(DllMutex);

    public:
        // ����UseCriticalSectionֻ��Windowsƽ̨��Ч����Windowsƽ̨���Զ�ת����UseDefault��
        explicit DllMutex(MutexCreate mutexCreate = MutexCreate::UseCriticalSection);
        virtual ~DllMutex() noexcept = default;
        DllMutex(const DllMutex&) = delete;
        virtual DllMutex& operator=(const DllMutex&) = delete;
        DllMutex(DllMutex&& rhs) noexcept;
        virtual DllMutex& operator=(DllMutex&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] bool TryEnter();
        void Enter();
        void Leave() noexcept;

        virtual void Initialize();
        virtual void Delete() noexcept;

    private:
        IMPL_TYPE_DECLARE(DllMutex);
    };
}

#endif  // CORE_TOOLS_THREADING_DLL_MUTEX_H
