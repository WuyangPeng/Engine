// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 14:40)

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
		using ShaderFloatSharedPtrGather = std::vector<ShaderFloatSharedPtr>;
		using TextureSharedPtrGather = std::vector<TextureSharedPtr>;
		using ConstShaderFloatSharedPtrGather = std::vector<ConstShaderFloatSharedPtr>;
		using ConstTextureSharedPtrGather = std::vector<ConstTextureSharedPtr>;

	public:
                ShaderParametersImpl() noexcept;
		explicit ShaderParametersImpl(const ConstShaderBaseSharedPtr& shader);

		ShaderParametersImpl(const ShaderParametersImpl& rhs);
		ShaderParametersImpl& operator=(const ShaderParametersImpl& rhs);
                ShaderParametersImpl(ShaderParametersImpl&&) = default;
                ShaderParametersImpl& operator=(ShaderParametersImpl&&) = default;
                ~ShaderParametersImpl() = default;

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
	
		int GetNumConstants () const;
		int GetNumTextures () const;
		const ConstShaderFloatSharedPtrGather GetConstants() const;
		const ConstTextureSharedPtrGather GetTextures() const;
		
		// ��Щ�����趨����/����
		// ����ɹ�������ֵΪ�Ǹ�ֵ�������ǵ���Ӧ�����е�������
		// ���������ܻᴫ�ݵ�Set*�������в�����handle����
		// �û���������ֱ��ͨ���������ã�
		// ������Set*���������������const std::string& name�������ֱȽϡ�
		int SetConstant(const std::string& name, const ShaderFloatSharedPtr& shaderFloat);
		int SetTexture (const std::string& name, const TextureSharedPtr& texture);
		
		// ��handle����������Set*�����ķ���ֵ��
		void SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat);
		void SetTexture(int handle, const TextureSharedPtr& texture);
	
		const ConstShaderFloatSharedPtr GetConstant(const std::string& name) const;
		const ConstTextureSharedPtr GetTexture(const std::string& name) const;
		
		// ��handle����������Set*�����ķ���ֵ��
		const ConstShaderFloatSharedPtr GetConstant(int handle) const;
		const ConstTextureSharedPtr GetTexture(int handle) const;
		
		// ������ɫ�������ڻ��Ƶ����ڼ䡣
		void UpdateConstants (const VisualSharedPtr& visual, const CameraSharedPtr& camera);

	private:
		void Swap(ShaderParametersImpl& rhs);
		
	private:
		ConstShaderBaseSharedPtr m_Shader;
		ShaderFloatSharedPtrGather m_Constants;
		TextureSharedPtrGather m_Textures;
	};
}

#endif // RENDERING_SHADERS_SHADER_PARAMETERS_IMPL_H
