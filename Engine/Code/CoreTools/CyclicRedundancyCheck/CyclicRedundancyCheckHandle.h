//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:52)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_UNIQUE_PTR(CyclicRedundancyCheckHandle);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(CyclicRedundancyCheckHandleImpl); 

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckHandle final : public Singleton<CyclicRedundancyCheckHandle>
    {
    public:
        NON_COPY_TYPE_DECLARE(CyclicRedundancyCheckHandle);
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
        PackageType impl;
    };
}

#define CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON CoreTools::CyclicRedundancyCheckHandle::GetSingleton()

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
