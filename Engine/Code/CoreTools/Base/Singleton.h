//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 9:52)

// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��Ҳ����ͨ������������ʹ��new��delete���Լ�����
// ����ֱ��ʹ��StaticSingleton��
// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
// �����ڴ���������ʱû�м��������뱣֤���̴߳���
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

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
        [[nodiscard]] static ReferenceType GetSingleton() noexcept;
        [[nodiscard]] static PointType GetSingletonPtr() noexcept;

    protected:
        Singleton() noexcept;
        ~Singleton() noexcept;
        [[nodiscard]] static Mutex& GetMutex();

    public:
        Singleton(const Singleton& rhs) noexcept = delete;
        Singleton& operator=(const Singleton& rhs) noexcept = delete;
        Singleton(Singleton&& rhs) noexcept = delete;
        Singleton& operator=(Singleton&& rhs) noexcept = delete;

    private:
        void InitSingleton();
        void DeleteSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        static void CheckSingleton();

    private:
        static PointType sm_Singleton;
    };
}

#endif  // CORE_TOOLS_BASE_SINGLETON_H
