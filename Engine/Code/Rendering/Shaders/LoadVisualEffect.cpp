///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 14:18)

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
