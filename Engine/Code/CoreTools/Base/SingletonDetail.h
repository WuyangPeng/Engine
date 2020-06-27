// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 09:54)

#ifndef CORE_TOOLS_BASE_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_SINGLETON_DETAIL_H

#include "Singleton.h"
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

template <typename T>
typename CoreTools::Singleton<T>::PointType CoreTools::Singleton<T>
	::sm_Singleton{ nullptr };


template <typename T>
CoreTools::Mutex* CoreTools::Singleton<T>
	::sm_Mutex{ nullptr };

template <typename T>
CoreTools::Singleton<T>
	::Singleton() noexcept 
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)
	#include SYSTEM_WARNING_DISABLE(26491)
	#include SYSTEM_WARNING_DISABLE(26409)

		CORE_TOOLS_ASSERTION_2(sm_Singleton == nullptr, "单例%s重复初始化！", typeid(T).name());
		
		sm_Singleton = static_cast<T*>(this);

		CORE_TOOLS_ASSERTION_0(sm_Singleton != nullptr, "单例%s初始化失败！", typeid(T).name());

		sm_Mutex = new Mutex;

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// 捕获所有异常，这里不能有任何逻辑，以免造成递归调用。
	}
}

template <typename T>
CoreTools::Singleton<T>
	::~Singleton() noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		delete sm_Mutex;

		CORE_TOOLS_ASSERTION_2(sm_Singleton != nullptr, "单例%s重复删除！", typeid(T).name());

		sm_Singleton = nullptr;

		CORE_TOOLS_ASSERTION_2(sm_Singleton == nullptr, "单例%s删除失败！", typeid(T).name());

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// 捕获所有异常，这里不能有任何逻辑，以免造成递归调用。
	}
}

template <typename T>
typename CoreTools::Singleton<T>::ReferenceType CoreTools::Singleton<T>
	::GetSingleton() noexcept
{
	return *GetSingletonPtr();
}

template <typename T>
typename CoreTools::Singleton<T>::PointType CoreTools::Singleton<T>
	::GetSingletonPtr() noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		CORE_TOOLS_ASSERTION_0(sm_Singleton != nullptr, "单例%s指针为空！", typeid(T).name()); 	 

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// 捕获所有异常，这里不能有任何逻辑，以免造成递归调用。
	}

	return sm_Singleton;
} 

template <typename T>
CoreTools::Mutex& CoreTools::Singleton<T>
	::GetMutex() noexcept
{
	return *sm_Mutex;
}

#endif // CORE_TOOLS_BASE_SINGLETON_DETAIL_H

