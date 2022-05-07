///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 14:46)

#include "Rendering/RenderingExport.h"

#include "SaveVisualEffect.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SaveVisualEffect::SaveVisualEffect(const VisualEffect& visualEffect, const System::String& fileName)
{
    CoreTools::WriteFileManager manager{ fileName };

    visualEffect.SaveVisualTechnique(manager);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SaveVisualEffect)
