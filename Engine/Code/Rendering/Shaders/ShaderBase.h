// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:19)

#ifndef RENDERING_SHADERS_SHADER_H
#define RENDERING_SHADERS_SHADER_H

#include "Rendering/RenderingDll.h"

#include "ShaderProfileData.h"
#include "Flags/ShaderFlags.h"
#include "Rendering/DataTypes/Colour.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

#include <string>

RENDERING_EXPORT_SHARED_PTR(ShaderBaseImpl);

namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderBase : public CoreTools::Object
    {
    public:
		OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderBase);
		using ParentType = Object;
		using Colour = Colour<float>;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

		// Ĭ�� lodBias �� 0.
		// Ĭ�� anisotropy �� 1.
		// Ĭ�� borderColor �� (0,0,0,0).
        
    public:   
		// ����VertexShader��PixelShader�Ļ��ࡣ
		// �����ݵĶ�����ɫ��������������ɫ����������ɫ�������ʵ����
		// ��ˣ���ɫ����ÿ��ʵ�������ǵ�����ͨ����shaderName����ʶ��
		// ���λ�ͼ�漰��ɫ���������ࣩ��ShaderParameters�������������ʵ������
    
		// ���캯��������붯̬�ط��䡣��ɫ���е�ɾ�����ǵ����Ρ�
		// ֱ��ͨ��SetProgram�����ṩ�����г������ڸ����Ͳģ�
		// ��ɫ���Ľṹ�ǲ������ġ�
        ShaderBase (const std::string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers);    
          ~ShaderBase () = 0;

		  #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        ShaderBase(ShaderBase&&) noexcept = default;
        ShaderBase& operator=(ShaderBase&&) noexcept = default;
		 #include STSTEM_WARNING_POP

		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderBase); 

		void SetInput (int index, const std::string& name,ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);
		
		void SetOutput (int index, const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);
		
		void SetConstant (int index, const std::string& name,int numRegistersUsed);
		
		void SetSampler (int index, const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (int index, ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int index, int dimension,ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (int index, float lodBias);
		void SetAnisotropy (int index, float anisotropy);
		void SetBorderColor (int index, const Colour& borderColor);
        
		int GetNumInputs () const;
		const std::string GetInputName (int index) const;
		ShaderFlags::VariableType GetInputType (int index) const;
		ShaderFlags::VariableSemantic GetInputSemantic (int index) const;
		
		int GetNumOutputs () const;
		const std::string GetOutputName (int index) const;
		ShaderFlags::VariableType GetOutputType (int index) const;
		ShaderFlags::VariableSemantic GetOutputSemantic (int index) const;
		
		int GetNumConstants () const;
		const std::string GetConstantName (int index) const;
		int GetNumRegistersUsed (int index) const;
		
		int GetNumSamplers () const;
		const std::string GetSamplerName (int index) const;
		ShaderFlags::SamplerType GetSamplerType (int index) const;
		ShaderFlags::SamplerFilter GetFilter (int index) const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int index, int dimension) const;
		float GetLodBias (int index) const;
		float GetAnisotropy (int index) const;
		Colour GetBorderColor (int index) const;

		void SaveShader(WriteFileManager& manager) const;
		void LoadShader(ReadFileManager& manager, int numProfiles);

		void SetProfile(const ShaderProfileDataSmartPointer& profile) noexcept;
                const ConstShaderProfileDataSmartPointer GetProfile() const noexcept;

		ShaderProfileDataSmartPointer GetProfile() noexcept;

    private:
		IMPL_TYPE_DECLARE(ShaderBase);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ShaderBase);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ShaderBase);
}

#endif // RENDERING_SHADERS_SHADER_H
