///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:52)

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
