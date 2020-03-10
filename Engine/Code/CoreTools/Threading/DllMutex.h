// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_DLL_MUTEX_H
#define CORE_TOOLS_THREADING_DLL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "Flags/MutexFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(MutexImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE DllMutex : private boost::noncopyable
	{
	public:
		using DllMutexImpl = MutexImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(DllMutex);

	public:
		// ����UseCriticalSectionֻ��Windowsƽ̨��Ч����Windowsƽ̨���Զ�ת����UseDefault��
		explicit DllMutex(MutexCreate mutexCreate = MutexCreate::UseCriticalSection);
		virtual ~DllMutex ();
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		bool TryEnter();
		void Enter();
		void Leave();

		virtual void Initialize();
        virtual void Delete();

	private:
		IMPL_TYPE_DECLARE(DllMutex);
	};
}

#endif // CORE_TOOLS_THREADING_DLL_MUTEX_H
