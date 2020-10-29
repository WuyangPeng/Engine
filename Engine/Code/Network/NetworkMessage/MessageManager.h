//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:03)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

NETWORK_EXPORT_UNIQUE_PTR(MessageManager);
NETWORK_EXPORT_SHARED_PTR(MessageManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageManager final : public CoreTools::Singleton<MessageManager>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(MessageManager);
        using ParentType = Singleton<MessageManager>;
        using FactoryFunction = MessageInterface::FactoryFunction;

    private:
        enum class MessageManagerCreate
        {
            Init,
        };

    public:
        explicit MessageManager(MessageManagerCreate messageManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(MessageManager);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] FactoryFunction Find(int64_t messageID, int version) const;
        void Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
        void Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition);
        void Remove(int64_t messageID);

        void SetFullVersion(int fullVersion);
        [[nodiscard]] int GetFullVersion() const;

    private:
        using MessageManagerUniquePtr = std::unique_ptr<MessageManager>;

    private:
        static MessageManagerUniquePtr sm_MessageManager;
        IMPL_TYPE_DECLARE(MessageManager);
    };
}

#define MESSAGE_MANAGER_SINGLETON Network::MessageManager::GetSingleton()

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGE_H
