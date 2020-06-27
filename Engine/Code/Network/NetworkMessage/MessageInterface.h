// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:30)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/RttiMacro.h" 
#include "Network/Helper/StreamMacro.h" 

namespace Network
{
	class NETWORK_DEFAULT_DECLARE MessageInterface
	{
	public:
		using MessageInterfaceSharedPtr = std::shared_ptr<MessageInterface>;
		using ConstMessageInterfaceSharedPtr = std::shared_ptr<const MessageInterface>;
		using ClassType = MessageInterface;
		using Rtti = CoreTools::Rtti;
		using FactoryFunction = MessageInterfaceSharedPtr(*)(const MessageSourceSharedPtr& stream, int64_t messageID);

	public:
		explicit MessageInterface(int64_t messageID);
		virtual ~MessageInterface() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		CORE_TOOLS_RTTI_DECLARE;

		bool IsExactly(const Rtti& type) const;
		bool IsDerived(const Rtti& type) const;
		bool IsExactlyTypeOf(const ConstMessageInterfaceSharedPtr& message) const;
		bool IsDerivedTypeOf(const ConstMessageInterfaceSharedPtr& message) const;

		static MessageInterfaceSharedPtr Factory(const MessageSourceSharedPtr& source, int64_t messageID);

		virtual int GetStreamingSize() const;
		virtual void Save(const MessageTargetSharedPtr& target) const;
		virtual void Load(const MessageSourceSharedPtr& source);

		virtual int GetMessageID() const;
		virtual int GetSubMessageID() const;
		int64_t GetFullMessageID() const noexcept;

		// int32_t 总长度
		// int32_t 版本号
		// int64_t 时间戳	
		static constexpr int GetMessageHeadSize()
		{
			return sizeof(int32_t) + sizeof(int32_t) + sizeof(int64_t);
		}

	protected:
		// 加载系统所使用的构造函数。
		enum class LoadConstructor
		{
			ConstructorLoader
		};

		MessageInterface(LoadConstructor value, int64_t messageID);

	private: 
		int64_t m_MessageID;
	};

	using MessageInterfaceSharedPtr = MessageInterface::MessageInterfaceSharedPtr;
	using ConstMessageInterfaceSharedPtr = MessageInterface::ConstMessageInterfaceSharedPtr;
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_INTERFACE_H
