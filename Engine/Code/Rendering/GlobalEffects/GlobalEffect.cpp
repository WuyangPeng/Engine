///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:48)

#include "Rendering/RenderingExport.h"

#include "GlobalEffect.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, GlobalEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, GlobalEffect);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, GlobalEffect);

Rendering::GlobalEffect::GlobalEffect(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "GlobalEffect" }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GlobalEffect)

Rendering::GlobalEffect::GlobalEffect(LoadConstructor value)
    : ParentType{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}
