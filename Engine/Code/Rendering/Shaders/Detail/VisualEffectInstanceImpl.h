// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:09)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VisualEffect.h"
#include "Rendering/Shaders/ShaderParameters.h"


namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class ObjectLink;
	class ObjectRegister;
	class Object; 
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE VisualEffectInstanceImpl
	{
	public:
		using ClassType = VisualEffectInstanceImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;

	public:
		VisualEffectInstanceImpl();
		VisualEffectInstanceImpl(const VisualEffectSharedPtr& effect, int techniqueIndex);

		VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs);
		VisualEffectInstanceImpl& operator=(const VisualEffectInstanceImpl& rhs);
                ~VisualEffectInstanceImpl() = default;
                VisualEffectInstanceImpl(VisualEffectInstanceImpl&&) noexcept = default;
                VisualEffectInstanceImpl& operator=(VisualEffectInstanceImpl&&) noexcept = default;
		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

		// 几何图元绘制过程中这些被Renderer使用。
		const ConstVisualEffectSharedPtr GetEffect() const;
		int GetTechniqueIndex() const;
		int GetNumPasses() const;
		const ConstVisualPassSharedPtr GetConstPass(int pass) const;
		const ConstShaderParametersSharedPtr GetConstVertexParameters(int pass) const;
		const ConstShaderParametersSharedPtr GetConstPixelParameters(int pass) const;
	 
		const ShaderParametersSharedPtr GetVertexParameters(int pass);
		const ShaderParametersSharedPtr GetPixelParameters(int pass);

		// 这些函数设定常数/纹理。
		// 如果成功，返回值是非负值，并且该索引指向相应的数组。
		// 该指索引可能会传递到Set*函数具有参数“句柄”。
		// 该机制允许您直接通过索引设置，避免使用参数“const std::string& name'Set*函数出现的名字比较。
		int SetVertexConstant(int pass, const std::string& name,const ShaderFloatSharedPtr& shaderFloat);

		int SetPixelConstant(int pass, const std::string& name,const ShaderFloatSharedPtr& shaderFloat);

		int SetVertexTexture(int pass, const std::string& name,const TextureSharedPtr& texture);

		int SetPixelTexture(int pass, const std::string& name,const TextureSharedPtr& texture);

		// “句柄”是上述的Set*函数的返回值。
		void SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
		void SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
		void SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture);
		void SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture);

 		const ConstShaderFloatSharedPtr GetVertexConstant(int pass, const std::string& name) const;
		const ConstShaderFloatSharedPtr GetPixelConstant(int pass, const std::string& name) const;
		const ConstTextureSharedPtr GetVertexTexture(int pass, const std::string& name) const;
		const ConstTextureSharedPtr GetPixelTexture(int pass, const std::string& name) const;

		const ConstShaderFloatSharedPtr GetVertexConstant(int pass, int handle) const;
		const ConstShaderFloatSharedPtr GetPixelConstant(int pass, int handle) const;
		const ConstTextureSharedPtr GetVertexTexture(int pass, int handle) const;
		const ConstTextureSharedPtr GetPixelTexture(int pass, int handle) const;

	private:
		void Swap( VisualEffectInstanceImpl& rhs);

	private:
		VisualEffectSharedPtr m_Effect;
		int m_TechniqueIndex;
		int m_NumPasses;
		std::vector<ShaderParametersSharedPtr> m_VertexParameters;
		std::vector<ShaderParametersSharedPtr> m_PixelParameters;
	};	 
}
 
#endif // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
