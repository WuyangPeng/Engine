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
EXPORT_SHARED_PTR(Rendering, LightConstantImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LightConstant : public ShaderFloat
	{
	public:
            void Swap(LightConstant& rhs) noexcept;
            
                public:
                    TYPE_DECLARE(LightConstant);
                    using ClassShareType = CoreTools::CopyUnsharedClasses;
                    ~LightConstant() noexcept= default;
                    LightConstant(const LightConstant& rhs);
                    LightConstant& operator=(const LightConstant& rhs);
                    LightConstant(LightConstant&& rhs) noexcept;
                    LightConstant& operator=(LightConstant&& rhs) noexcept;
		using ParentType = ShaderFloat;

	public:
		explicit LightConstant(const LightSharedPtr& light);
           

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) = 0;

		  void SetNumRegisters(int numRegisters) override;

		const ConstLightSharedPtr GetLight() const;

	private:
		constexpr static auto sm_NumRegisters = 1;

	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(LightConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( LightConstant);
}
#include STSTEM_WARNING_POP
#endif // RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_H
