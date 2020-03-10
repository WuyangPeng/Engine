// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:30)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

NETWORK_EXPORT_SHARED_PTR(MessageManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE MessageManager : public CoreTools::Singleton<MessageManager>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(MessageManager);
		using FactoryFunction = MessageInterface::FactoryFunction;

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		FactoryFunction Find(int64_t messageID, int version) const;
		void Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
		void Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition);
		void Remove(int64_t messageID);

		void SetFullVersion(int fullVersion);
		int GetFullVersion() const;

	private:
		SINGLETON_MEMBER_DECLARE(MessageManager);
	};
}

#define MESSAGE_MANAGER_SINGLETON Network::MessageManager::GetSingleton()

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGE_H
