/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:24)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

    template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::BaseEntity>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::BaseEntity>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BaseEntity : public std::enable_shared_from_this<BaseEntity>
    {
    public:
        using ClassType = BaseEntity;

    protected:
        explicit BaseEntity(DisableNotThrow disableNotThrow);

    public:
        virtual ~BaseEntity() noexcept = 0;
        BaseEntity(const BaseEntity& rhs) = default;
        BaseEntity& operator=(const BaseEntity& rhs) = default;
        BaseEntity(BaseEntity&& rhs) noexcept = default;
        BaseEntity& operator=(BaseEntity&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int64_t GetEntityId() const noexcept;

        void Register();

    private:
        virtual void DoRegister();

    private:
        int64_t entityId;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H