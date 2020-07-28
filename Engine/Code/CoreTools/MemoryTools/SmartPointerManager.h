// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H

// ��SmartPointerX<T>֧�ֶ�̬���乲���������T����ʹ��NEWD������������D��ά�ȣ�0,1,2�ȵȣ�X��Single��1DArray��2DArray�ȵȡ�
// TӦ��һ���������ͣ�������һ��ָ�����͡�
// ����ά��0������TҲ����ʹ��new���������䡣
// ����ά��1����������TҲ����ʹ��new[]���������䡣
// ����ά��D >= 2�������ʹ��NEWD��
// ���಻֧�ֹ�����ڶ�ջ�Ķ���Ҳ����˵������ͨ����T���͵Ķ���ĵ�ַѹ���ջ��

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

		// �����ж�thisָ���Ƿ�ΪSmartPointerManager����
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
