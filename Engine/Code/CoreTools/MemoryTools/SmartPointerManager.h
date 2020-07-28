// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H

// 该SmartPointerX<T>支持动态分配共享对象类型T，并使用NEWD操作符，这里D是维度（0,1,2等等）X是Single，1DArray，2DArray等等。
// T应是一个对象类型，而不是一个指针类型。
// 对于维度0，对象T也可以使用new操作符分配。
// 对于维度1，对象数组T也可以使用new[]操作符分配。
// 对于维度D >= 2，你必须使用NEWD。
// 该类不支持共享基于堆栈的对象。也就是说，不能通过将T类型的对象的地址压入堆栈。

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ThreadingFwd.h"
CORE_TOOLS_EXPORT_UNIQUE_PTR(SmartPointerManager);
CORE_TOOLS_EXPORT_SHARED_PTR(SmartPointerManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE SmartPointerManager : public CoreTools::Singleton<SmartPointerManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(SmartPointerManager);
		using ParentType = Singleton<SmartPointerManager>;

	private:
		enum class SmartPointerManagerCreate
		{
			Init,
		};

	public:
		explicit SmartPointerManager(SmartPointerManagerCreate smartPointerManagerCreate);

		static void Create();
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(SmartPointerManager);

		CLASS_INVARIANT_DECLARE;

		int CopyIncreaseReference(const void* data);
		int IncreaseReference(const void* data);
		int DecreaseReference(const void* data);

		// 用于判断this指针是否为SmartPointerManager创建
		bool IsSmartPointer(const void* data) const;

	private:
		using SmartPointerManagerUniquePtr = std::unique_ptr<SmartPointerManager>;

	private:
		static SmartPointerManagerUniquePtr sm_SmartPointerManager;
		IMPL_TYPE_DECLARE(SmartPointerManager);
	};
}

#define SMART_POINTER_SINGLETON CoreTools::SmartPointerManager::GetSingleton()

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H
