// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:56)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H
#define RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "ShaderFloat.h"
#include "Rendering/SceneGraph/Light.h"
#include "CoreTools/Helper/ExportMacro.h"

RENDERING_EXPORT_SHARED_PTR(LightConstantImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightConstant : public ShaderFloat
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(LightConstant);
		using ParentType = ShaderFloat;

	public:
		explicit LightConstant(const LightSmartPointer& light);
		virtual ~LightConstant();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		virtual void Update(const Visual* visual, const Camera* camera) = 0;

		virtual void SetNumRegisters(int numRegisters) override;

		const ConstLightSmartPointer GetLight() const;

	private:
		constexpr static auto sm_NumRegisters = 1;

	private:
		IMPL_TYPE_DECLARE(LightConstant);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(LightConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, LightConstant);
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H
