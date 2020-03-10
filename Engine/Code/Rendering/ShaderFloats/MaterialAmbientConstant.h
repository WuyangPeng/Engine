// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:02)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "MaterialConstant.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE MaterialAmbientConstant : public MaterialConstant
	{
	public:
		using ClassType = MaterialAmbientConstant;
		using ParentType = MaterialConstant;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		explicit MaterialAmbientConstant(const MaterialSmartPointer& material);
		virtual ~MaterialAmbientConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(MaterialAmbientConstant);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 

		virtual void Update(const Visual* visual, const Camera* camera) override;

		virtual ShaderFloatSmartPointer Clone() const override;
	};

	CORE_TOOLS_STREAM_REGISTER(MaterialAmbientConstant);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, MaterialAmbientConstant);
}

#endif // RENDERING_SHADER_FLOATS_MATERIAL_AMBIENT_CONSTANT_CONSTANT_H


 
