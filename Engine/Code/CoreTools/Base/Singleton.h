// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 09:55)

// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��
// Ҳ����ͨ������������ʹ��new��delete���Լ�����
// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
// �����ڴ���������ʱû�м��������뱣֤���̴߳���
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

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
		static ReferenceType GetSingleton() noexcept;
		static PointType GetSingletonPtr() noexcept;		

	protected:
		Singleton() noexcept;
		~Singleton() noexcept;
		static Mutex& GetMutex() noexcept;

	public:
		Singleton(const Singleton&) noexcept = delete;
		Singleton& operator=(const Singleton&)  noexcept  = delete;
		Singleton(Singleton&& rhs) noexcept = delete;
		Singleton& operator=(Singleton&& rhs) noexcept = delete; 

	private:
		static PointType sm_Singleton;
		static Mutex* sm_Mutex;
	};
}

#endif // CORE_TOOLS_BASE_SINGLETON_H

