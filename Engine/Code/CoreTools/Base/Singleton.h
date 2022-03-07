///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 14:27)

/// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
/// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��Ҳ����ͨ������������ʹ��new��delete���Լ���������ֱ��ʹ��StaticSingleton��
/// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
/// �����ڴ���������ʱû�м��������뱣֤���̴߳���
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/Flags/MutexTraits.h"

#include <mutex>

namespace CoreTools
{
    template <typename T, MutexCreate mutexCreate = MutexCreate::UseOriginalStdRecursive>
    class Singleton
    {
    public:
        using ClassType = Singleton<T, mutexCreate>;
        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;
        using MutexType = typename MutexTraits<mutexCreate>::MutexType;

    public:
        NODISCARD static ReferenceType GetSingleton() noexcept;
        NODISCARD static PointType GetSingletonPtr() noexcept;

    protected:
        Singleton() noexcept;
        ~Singleton() noexcept;
        NODISCARD static MutexType& GetMutex();

    public:
        Singleton(const Singleton& rhs) noexcept = delete;
        Singleton& operator=(const Singleton& rhs) noexcept = delete;
        Singleton(Singleton&& rhs) noexcept = delete;
        Singleton& operator=(Singleton&& rhs) noexcept = delete;

    private:
        void InitSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void DeleteSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        static void CheckSingleton() noexcept(g_Assert < 0 || g_CoreToolsAssert < 0);

    private:
        static PointType singleton;
    };
}

#endif  // CORE_TOOLS_BASE_SINGLETON_H
