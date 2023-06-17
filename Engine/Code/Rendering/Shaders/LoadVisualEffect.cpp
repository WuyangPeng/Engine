///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:51)

#include "Rendering/RenderingExport.h"

#include "LoadVisualEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::LoadVisualEffect::LoadVisualEffect() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LoadVisualEffect)

Rendering::VisualEffectSharedPtr Rendering::LoadVisualEffect::Load(const System::String& fileName)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CoreTools::ReadFileManager manager{ fileName };

    auto effect = std::make_shared<VisualEffect>(CoreTools::DisableNotThrow::Disable);

    return effect;
}
