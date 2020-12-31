//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:14)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExportMacro.h"

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::BaseEntity>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::BaseEntity>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BaseEntity : public std::enable_shared_from_this<BaseEntity>
    {
    public:
        using ClassType = BaseEntity;

    public:
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        BaseEntity();
        virtual ~BaseEntity() noexcept = 0;
        BaseEntity(const BaseEntity& rhs) = default;
        BaseEntity& operator=(const BaseEntity& rhs) = default;
        BaseEntity(BaseEntity&& rhs) noexcept = default;
        BaseEntity& operator=(BaseEntity&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] uint64_t GetEntityID() const noexcept;

        void Register();

    private:
        virtual void DoRegister();

    private:
        uint64_t m_EntityID;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H