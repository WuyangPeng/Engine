///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:52)

#include "Rendering/RenderingExport.h"

#include "SaveVisualEffect.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SaveVisualEffect::SaveVisualEffect(MAYBE_UNUSED const VisualEffect& visualEffect, const System::String& fileName)
{
    CoreTools::WriteFileManager manager{ fileName };

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SaveVisualEffect)
