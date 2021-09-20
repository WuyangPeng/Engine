///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 19:02)

/// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
/// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��Ҳ����ͨ������������ʹ��new��delete���Լ���������ֱ��ʹ��StaticSingleton��
/// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
/// �����ڴ���������ʱû�м��������뱣֤���̴߳���
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Threading/Mutex.h"

namespace CoreTools
{
    template <typename T>
    class Singleton
    {
    public:
        using ClassType = Singleton<T>;
        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;

    public:
        NODISCARD static ReferenceType GetSingleton() noexcept;
        NODISCARD static PointType GetSingletonPtr() noexcept;

    protected:
        Singleton() noexcept;
        ~Singleton() noexcept;
        NODISCARD static Mutex& GetMutex();

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
