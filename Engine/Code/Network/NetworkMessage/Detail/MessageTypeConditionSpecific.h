// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:25)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H

#include "Network/NetworkDll.h" 

#include "MessageTypeConditionImpl.h" 

#include <set>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageTypeConditionSpecific : public MessageTypeConditionImpl
	{
	public:
		using ClassType = MessageTypeConditionSpecific;
		using ParentType = MessageTypeConditionImpl;
		using VersionType = std::set<int>;

	public:
		explicit MessageTypeConditionSpecific(const VersionType& version);
 
		CLASS_INVARIANT_OVERRIDE_DECLARE;

	public:
		  bool IsVersionsConform(int version) const override;
		  int GetMinVersion() const override;
		  int GetMaxVersion() const override;

	private:
		VersionType m_Version;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_SPECIFIC_H
