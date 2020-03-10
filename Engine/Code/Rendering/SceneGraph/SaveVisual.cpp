// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 18:04)

#include "Rendering/RenderingExport.h"

#include "SaveVisual.h"
#include "Visual.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

using CoreTools::WriteFileManager;

void Rendering::SaveVisual
	::SaveToFile(const Visual& visual, const System::String& name)
{
	RENDERING_ASSERTION_0(!visual.GetConstVertexFormat().IsNullPtr(), "VertexFormatÊÇ¿ÕÖ¸Õë£¡");
	RENDERING_ASSERTION_0(!visual.GetConstVertexBuffer().IsNullPtr(), "VertexBufferÊÇ¿ÕÖ¸Õë£¡");

	WriteFileManager manager{ name };

	auto type = System::EnumCastUnderlying(visual.GetPrimitiveType());
	manager.Write(sizeof(int), &type);

	visual.GetConstVertexFormat()->SaveToFile(manager);
	visual.GetConstVertexBuffer()->SaveToFile(manager, visual.GetConstVertexFormat());

	if (!visual.GetConstIndexBuffer().IsNullPtr())
	{
		visual.GetConstIndexBuffer()->SaveToFile(manager);
	}
	else
	{
		int numElements{ 0 };
		manager.Write(sizeof(int), &numElements);
	}
}

