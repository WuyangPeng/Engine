///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 14:46)

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
