//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/19 16:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H

// ��SmartPointerX<T>֧�ֶ�̬���乲���������T����ʹ��NEWD������������D��ά�ȣ�0,1,2�ȵȣ�X��Single��1DArray��2DArray�ȵȡ�
// TӦ��һ���������ͣ�������һ��ָ�����͡�
// ����ά��0������TҲ����ʹ��new���������䡣
// ����ά��1����������TҲ����ʹ��new[]���������䡣
// ����ά��D >= 2�������ʹ��NEWD��
// ���಻֧�ֹ�����ڶ�ջ�Ķ���Ҳ����˵������ͨ����T���͵Ķ���ĵ�ַѹ���ջ��

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(SmartPointerManager);
CORE_TOOLS_EXPORT_SHARED_PTR(SmartPointerManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SmartPointerManager final : public CoreTools::Singleton<SmartPointerManager>
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

        [[nodiscard]] int CopyIncreaseReference(const void* data);
        [[nodiscard]] int IncreaseReference(const void* data);
        [[nodiscard]] int DecreaseReference(const void* data);

        // �����ж�thisָ���Ƿ�ΪSmartPointerManager����
        [[nodiscard]] bool IsSmartPointer(const void* data) const;

    private:
        using SmartPointerManagerUniquePtr = std::unique_ptr<SmartPointerManager>;

    private:
        static SmartPointerManagerUniquePtr sm_SmartPointerManager;
        IMPL_TYPE_DECLARE(SmartPointerManager);
    };
}

#define SMART_POINTER_SINGLETON CoreTools::SmartPointerManager::GetSingleton()

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_MANAGER_H
