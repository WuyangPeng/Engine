///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 20:40)

#ifndef CORE_TOOLS_BASE_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_SINGLETON_DETAIL_H

#include "Singleton.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

template <typename T>
typename CoreTools::Singleton<T>::PointType CoreTools::Singleton<T>::singleton{ nullptr };

template <typename T>
CoreTools::Singleton<T>::Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::InitSingleton);
}

template <typename T>
void CoreTools::Singleton<T>::InitSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton == nullptr, "����%s�ظ���ʼ����", typeid(T).name());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26491)

    singleton = static_cast<T*>(this);

#include STSTEM_WARNING_POP
}

template <typename T>
CoreTools::Singleton<T>::~Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::DeleteSingleton);
}

template <typename T>
void CoreTools::Singleton<T>::DeleteSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton != nullptr, "����%s�ظ�ɾ����", typeid(T).name());

    singleton = nullptr;
}

template <typename T>
typename CoreTools::Singleton<T>::ReferenceType CoreTools::Singleton<T>::GetSingleton() noexcept
{
    return *GetSingletonPtr();
}

template <typename T>
typename CoreTools::Singleton<T>::PointType CoreTools::Singleton<T>::GetSingletonPtr() noexcept
{
    System::NoexceptNoReturn(&ClassType::CheckSingleton);

    return singleton;
}

template <typename T>
void CoreTools::Singleton<T>::CheckSingleton() noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(singleton != nullptr, "����%sָ��Ϊ�գ�", typeid(T).name());
}

template <typename T>
CoreTools::Mutex& CoreTools::Singleton<T>::GetMutex()
{
    static Mutex mutex{};

    return mutex;
}

#endif  // CORE_TOOLS_BASE_SINGLETON_DETAIL_H
