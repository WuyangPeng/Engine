//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 15:14)

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

        [[nodiscard]] bool Register(const EntitySharedPtr& entity);
        [[nodiscard]] bool Unregister(uint64_t entityID);

        [[nodiscard]] EntitySharedPtr GetEntity(uint64_t entityID) const;

    private:
        using EntityWeakPtrContainer = std::map<uint64_t, EntityWeakPtr>;

    private:
        EntityWeakPtrContainer m_Container;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H