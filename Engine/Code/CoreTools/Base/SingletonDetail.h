// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 09:54)

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

		CORE_TOOLS_ASSERTION_2(sm_Singleton == nullptr, "����%s�ظ���ʼ����", typeid(T).name());
		
		sm_Singleton = static_cast<T*>(this);

		CORE_TOOLS_ASSERTION_0(sm_Singleton != nullptr, "����%s��ʼ��ʧ�ܣ�", typeid(T).name());

		sm_Mutex = new Mutex;

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// ���������쳣�����ﲻ�����κ��߼���������ɵݹ���á�
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

		CORE_TOOLS_ASSERTION_2(sm_Singleton != nullptr, "����%s�ظ�ɾ����", typeid(T).name());

		sm_Singleton = nullptr;

		CORE_TOOLS_ASSERTION_2(sm_Singleton == nullptr, "����%sɾ��ʧ�ܣ�", typeid(T).name());

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// ���������쳣�����ﲻ�����κ��߼���������ɵݹ���á�
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

		CORE_TOOLS_ASSERTION_0(sm_Singleton != nullptr, "����%sָ��Ϊ�գ�", typeid(T).name()); 	 

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// ���������쳣�����ﲻ�����κ��߼���������ɵݹ���á�
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

