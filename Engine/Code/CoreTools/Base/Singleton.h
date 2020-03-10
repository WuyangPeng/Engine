// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 09:55)

// �Զ�Singleton��������������������Ҫ�ֶ����ƴ��������١�
// ���ʵ����˳�򲢲���Ҫ������ͨ������������Ϊȫ�ֻ�ֲ���̬��
// Ҳ����ͨ������������ʹ��new��delete���Լ�����
// ��̬��Ͷ�̬�����ʱ�ᵼ�²�ͬdll��exeʹ�ò�ͬ�ĵ�������Ҫ���⴦��
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template <typename T>
	class Singleton : private boost::noncopyable
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
		virtual ~Singleton() noexcept;

	private:
		static PointType sm_Singleton;
	};
}

#endif // CORE_TOOLS_BASE_SINGLETON_H

