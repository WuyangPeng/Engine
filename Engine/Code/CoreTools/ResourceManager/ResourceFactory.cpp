// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:10)

#include "CoreTools/CoreToolsExport.h"

#include "ResourceFactory.h"
#include "CoreTools/ResourceManager/CommonDataResource.h"
#include "CoreTools/ResourceManager/BaseResourceManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::ResourceFactory
	::ResourceFactory(BaseResourceManager& resourceManager)
	:m_ResourceManager{ resourceManager }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ResourceFactory
	::~ResourceFactory()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ResourceFactory)

uint32_t CoreTools::ResourceFactory
	::CreateResource(PriorityType type, int size)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	BaseResourceManager::ResourceSharedPtr ptr{ make_shared<CommonDataResource>(type,size) };

	auto id = m_ResourceManager.InsertResource(ptr);

	return id;
}

