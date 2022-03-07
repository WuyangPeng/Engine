///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/25 20:28)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "System/Helper/PragmaWarning.h"
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
        explicit BaseEntity(MAYBE_UNUSED DisableNotThrow dDisableNotThrow);

    public:
        virtual ~BaseEntity() noexcept = 0;
        BaseEntity(const BaseEntity& rhs) = default;
        BaseEntity& operator=(const BaseEntity& rhs) = default;
        BaseEntity(BaseEntity&& rhs) noexcept = default;
        BaseEntity& operator=(BaseEntity&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD uint64_t GetEntityID() const noexcept;

        void Register();

    private:
        virtual void DoRegister();

    private:
        uint64_t entityID;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H