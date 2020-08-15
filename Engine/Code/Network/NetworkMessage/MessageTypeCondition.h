// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:32)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H

#include "Network/NetworkDll.h" 

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h" 

#include <set>

NETWORK_EXPORT_SHARED_PTR(MessageTypeConditionImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE MessageTypeCondition
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(MessageTypeCondition);
		using VersionType = std::set<int>;

	public:
		explicit MessageTypeCondition(const VersionType& version);
		MessageTypeCondition(int beginVersion, int endVersion);
		MessageTypeCondition(VersionsCondition condition, int version);
		MessageTypeCondition();

		CLASS_INVARIANT_DECLARE;

	public:
		bool IsVersionsConform(int version) const;
		int GetMinVersion() const;
		int GetMaxVersion() const;

		bool operator<(const MessageTypeCondition& rhs) const;

	private:
		IMPL_TYPE_DECLARE(MessageTypeCondition);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_H
