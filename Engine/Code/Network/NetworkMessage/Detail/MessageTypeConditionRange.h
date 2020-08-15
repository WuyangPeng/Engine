// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:25)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H

#include "Network/NetworkDll.h" 

#include "MessageTypeConditionImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageTypeConditionRange : public MessageTypeConditionImpl
	{
	public:
		using ClassType = MessageTypeConditionRange;
		using ParentType = MessageTypeConditionImpl;

	public:
		MessageTypeConditionRange(int beginVersion, int endVersion);
		 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
                bool IsVersionsConform(int version) const noexcept override;
            int GetMinVersion() const noexcept override;
                int GetMaxVersion() const noexcept override;

	private:
		int m_BeginVersion;
		int m_EndVersion;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
