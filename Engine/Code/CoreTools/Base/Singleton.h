/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 16:36)

/// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
/// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��
/// Ҳ����ͨ������������ʹ��new��delete���Լ���������ֱ��ʹ��StaticSingleton��
/// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
/// �����ڴ���������ʱû�м��������뱣֤���̴߳���
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/Flags/MutexTraits.h"

namespace CoreTools
{
    template <typename T, MutexCreate MutexCreate = MutexCreate::UseOriginalStdRecursive>
    class Singleton
    {
    public:
        using ClassType = Singleton<T, MutexCreate>;

        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;
        using MutexType = typename MutexTraits<MutexCreate>::MutexType;

    public:
        NODISCARD static ReferenceType GetSingleton() noexcept;
        NODISCARD static PointType GetSingletonPtr() noexcept;

    protected:
        static constexpr auto isStdMutex = MutexCreate == MutexCreate::UseOriginalStd || MutexCreate == MutexCreate::UseOriginalStdRecursive;

    protected:
        Singleton() noexcept;
        ~Singleton() noexcept;
        NODISCARD static MutexType& GetMutex() noexcept requires(isStdMutex);
        NODISCARD static MutexType& GetMutex() requires(!isStdMutex);

    public:
        Singleton(const Singleton& rhs) noexcept = delete;
        Singleton& operator=(const Singleton& rhs) noexcept = delete;
        Singleton(Singleton&& rhs) noexcept = delete;
        Singleton& operator=(Singleton&& rhs) noexcept = delete;

    private:
        void InitSingleton() noexcept(gAssert < 2 || gCoreToolsAssert < 2);
        void DeleteSingleton() const noexcept(gAssert < 2 || gCoreToolsAssert < 2);
        static void CheckSingleton() noexcept(gAssert < 0 || gCoreToolsAssert < 0);

    private:
        static PointType singleton;
    };
}

#endif  // CORE_TOOLS_BASE_SINGLETON_H
