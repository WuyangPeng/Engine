// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 16:25)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionAll.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/VersionInformation/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageManager.h"

Network::MessageTypeConditionAll
	::MessageTypeConditionAll() noexcept
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionAll)

bool Network::MessageTypeConditionAll
	::IsVersionsConform(int version) const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(version);

	return true;
}

int Network::MessageTypeConditionAll ::GetMinVersion() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

int Network::MessageTypeConditionAll
	::GetMaxVersion() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return MESSAGE_MANAGER_SINGLETON.GetFullVersion();
}
