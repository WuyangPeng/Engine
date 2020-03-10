// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 16:57)

#include "Rendering/RenderingExport.h"

#include "SaveVisualEffect.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/FileManager/WriteFileManager.h"

Rendering::SaveVisualEffect
	::SaveVisualEffect(const VisualEffectSmartPointer& visualEffect, const System::String& fileName)
{
	CoreTools::WriteFileManager manager{ fileName };

	visualEffect->SaveVisualTechnique(manager);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,SaveVisualEffect)


