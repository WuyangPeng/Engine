// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 14:40)

#ifndef RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H
#define RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture.h"
#include "Rendering/Shaders/ShaderBase.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

#include <vector>
#include <string>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class ObjectRegister;
	class ObjectLink;
	class Object;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderParametersImpl
	{
	public:
		using ClassType = ShaderParametersImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;
		using ShaderFloatSmartPointerGather = std::vector<ShaderFloatSmartPointer>;
		using TextureSmartPointerGather = std::vector<TextureSmartPointer>;
		using ConstShaderFloatSmartPointerGather = std::vector<ConstShaderFloatSmartPointer>;
		using ConstTextureSmartPointerGather = std::vector<ConstTextureSmartPointer>;

	public:
                ShaderParametersImpl() noexcept;
		explicit ShaderParametersImpl(const ConstShaderBaseSmartPointer& shader);

		ShaderParametersImpl(const ShaderParametersImpl& rhs);
		ShaderParametersImpl& operator=(const ShaderParametersImpl& rhs);
                ShaderParametersImpl(ShaderParametersImpl&&) = default;
                ShaderParametersImpl& operator=(ShaderParametersImpl&&) = default;
                ~ShaderParametersImpl() = default;

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		void Link(ObjectLink& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
	
		int GetNumConstants () const;
		int GetNumTextures () const;
		const ConstShaderFloatSmartPointerGather GetConstants() const;
		const ConstTextureSmartPointerGather GetTextures() const;
		
		// 这些函数设定常理/纹理。
		// 如果成功，返回值为非负值，并且是到相应的阵列的索引。
		// 该索引可能会传递到Set*函数具有参数“handle”。
		// 该机制允许您直接通过索引设置，
		// 避免与Set*函数出现与参数“const std::string& name”的名字比较。
		int SetConstant(const std::string& name, const ShaderFloatSmartPointer& shaderFloat);
		int SetTexture (const std::string& name, const TextureSmartPointer& texture);
		
		// “handle”是上述的Set*函数的返回值。
		void SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetTexture(int handle, const TextureSmartPointer& texture);
	
		const ConstShaderFloatSmartPointer GetConstant(const std::string& name) const;
		const ConstTextureSmartPointer GetTexture(const std::string& name) const;
		
		// “handle”是上述的Set*函数的返回值。
		const ConstShaderFloatSmartPointer GetConstant(int handle) const;
		const ConstTextureSmartPointer GetTexture(int handle) const;
		
		// 更新着色器常量在绘制调用期间。
		void UpdateConstants (const VisualSmartPointer& visual, const CameraSmartPointer& camera);

	private:
		void Swap(ShaderParametersImpl& rhs);
		
	private:
		ConstShaderBaseSmartPointer m_Shader;
		ShaderFloatSmartPointerGather m_Constants;
		TextureSmartPointerGather m_Textures;
	};
}

#endif // RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H
