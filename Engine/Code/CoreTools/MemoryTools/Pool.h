// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_POOL_H
#define CORE_TOOLS_MEMORY_TOOLS_POOL_H

// ����ر�����ǰ���������б��Ӷ�ʹ�����ظ�ʹ�õĶ���û�б��ͷŶ����²��ϵ����·��䡣
// �ö���ظ��ٵ��������һ���޲����Ĺ��캯�������ԣ������ʺϼ򵥵Ľṹ��

// �������ͷ�ʱ�����Ǳ���ӵ�����صĿ����б�Ϊ�����ڴ�й©������δ����Ķ���Ӧ�ñ��ͷţ�
// ���Ե�����ر�ɾ��ʱ�������ڴ潫���ͷš�Ҳ������ʱ����FreeAll��λ�ͷŶ���ء�

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <list>

namespace CoreTools
{
	template<class T>
	class Pool : private boost::noncopyable
	{
	public:
		using ClassType = Pool;

	public:
		Pool();
		virtual ~Pool();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// ������ܵĻ����ӿ��еĴ洢�л�ö��󣬷�������·�������
		virtual T* Get();

		virtual void Release(T* ptr);

		void FreeAll();

		int GetAvailableCount() const;
		int GetAllocatedCount() const noexcept;
		int GetTotalCount() const;

	protected:
		using StoreType = std::list<T*>;

	private:
		T* GetConformCondition();
		virtual bool ConformCondition(T* ptr);
		virtual T* DoGet();

	private:
		StoreType m_Store;
		int m_AllocatedCount;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_POOL_H
