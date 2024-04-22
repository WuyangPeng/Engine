/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:24)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/MessageEventFwd.h"

#include <map>

    namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EntityManagerImpl final
    {
    public:
        using ClassType = EntityManagerImpl;

        using EntitySharedPtr = std::shared_ptr<BaseEntity>;
        using EntityWeakPtr = std::weak_ptr<BaseEntity>;

    public:
        EntityManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Register(const EntitySharedPtr& entity);
        NODISCARD bool UnRegister(int64_t entityId) noexcept;

        NODISCARD EntitySharedPtr GetEntity(int64_t entityId) const;

    private:
        using EntityWeakPtrContainer = std::map<int64_t, EntityWeakPtr>;

    private:
        EntityWeakPtrContainer container;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H