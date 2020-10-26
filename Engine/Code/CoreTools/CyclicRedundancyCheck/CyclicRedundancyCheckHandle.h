//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:52)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(CyclicRedundancyCheckHandle);
CORE_TOOLS_EXPORT_SHARED_PTR(CyclicRedundancyCheckHandleImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckHandle final : public Singleton<CyclicRedundancyCheckHandle>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(CyclicRedundancyCheckHandle);
        using ParentType = Singleton<CyclicRedundancyCheckHandle>;

    private:
        enum class CyclicRedundancyCheckHandleCreate
        {
            Init,
        };

    public:
        explicit CyclicRedundancyCheckHandle(CyclicRedundancyCheckHandleCreate cyclicRedundancyCheckHandleCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(CyclicRedundancyCheckHandle);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint16_t GetCCITT(int index) const;
        [[nodiscard]] uint16_t Get16Table(int index) const;
        [[nodiscard]] uint32_t Get32Table(int index) const;

    private:
        using CyclicRedundancyCheckHandleUniquePtr = std::unique_ptr<CyclicRedundancyCheckHandle>;

    private:
        static CyclicRedundancyCheckHandleUniquePtr sm_CyclicRedundancyCheckHandle;
        IMPL_TYPE_DECLARE(CyclicRedundancyCheckHandle);
    };
}

#define CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON CoreTools::CyclicRedundancyCheckHandle::GetSingleton()

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
