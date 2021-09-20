// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:02)

#include "TestAbstractMessage.h" 
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h" 
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"

Network::TestAbstractMessage
	::TestAbstractMessage()
	:ParentType{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestAbstractMessage
	::~TestAbstractMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestAbstractMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestAbstractMessage);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, TestAbstractMessage);

Network::TestAbstractMessage
	::TestAbstractMessage(LoadConstructor value, int64_t messageID) noexcept
	: ParentType{ value,messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestAbstractMessage
	::Load(const Network::MessageSourceSharedPtr& source)
{
	NETWORK_CLASS_IS_VALID_9;

	NETWORK_BEGIN_STREAM_LOAD(source);

	ParentType::Load(source);

	NETWORK_END_STREAM_LOAD(source);
}

void Network::TestAbstractMessage
	::Save(const Network::MessageTargetSharedPtr& target) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	NETWORK_BEGIN_STREAM_SAVE(target);

	ParentType::Save(target);

	NETWORK_END_STREAM_SAVE(target);
}

int Network::TestAbstractMessage
	::GetStreamingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return ParentType::GetStreamingSize();
}


