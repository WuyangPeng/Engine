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
		
		// ��Щ�����趨����/����
		// ����ɹ�������ֵΪ�Ǹ�ֵ�������ǵ���Ӧ�����е�������
		// ���������ܻᴫ�ݵ�Set*�������в�����handle����
		// �û���������ֱ��ͨ���������ã�
		// ������Set*���������������const std::string& name�������ֱȽϡ�
		int SetConstant(const std::string& name, const ShaderFloatSmartPointer& shaderFloat);
		int SetTexture (const std::string& name, const TextureSmartPointer& texture);
		
		// ��handle����������Set*�����ķ���ֵ��
		void SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetTexture(int handle, const TextureSmartPointer& texture);
	
		const ConstShaderFloatSmartPointer GetConstant(const std::string& name) const;
		const ConstTextureSmartPointer GetTexture(const std::string& name) const;
		
		// ��handle����������Set*�����ķ���ֵ��
		const ConstShaderFloatSmartPointer GetConstant(int handle) const;
		const ConstTextureSmartPointer GetTexture(int handle) const;
		
		// ������ɫ�������ڻ��Ƶ����ڼ䡣
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
