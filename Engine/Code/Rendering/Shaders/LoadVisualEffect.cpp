// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 16:55)

#include "Rendering/RenderingExport.h"

#include "LoadVisualEffect.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::LoadVisualEffect
	::LoadVisualEffect()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,LoadVisualEffect)

const Rendering::VisualEffectSmartPointer Rendering::LoadVisualEffect
	::Load( const System::String& fileName )
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	CoreTools::ReadFileManager manager{ fileName };

	VisualEffectSmartPointer effect{ NEW0 VisualEffect };

	effect->LoadVisualTechnique(manager);

	return effect;
}

