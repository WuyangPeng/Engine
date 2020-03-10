// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:30)

#include "Rendering/RenderingExport.h"

#include "GlobalEffect.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering,GlobalEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,GlobalEffect);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,GlobalEffect); 

Rendering::GlobalEffect
	::GlobalEffect ()
	:ParentType{ "GlobalEffect" }
{
}

Rendering::GlobalEffect
	::~GlobalEffect ()
{
}

Rendering::GlobalEffect
	::GlobalEffect(LoadConstructor value)
	:ParentType{ value }
{
}