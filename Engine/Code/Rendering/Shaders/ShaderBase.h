// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:19)

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

		// 默认 lodBias 是 0.
		// 默认 anisotropy 是 1.
		// 默认 borderColor 是 (0,0,0,0).
        
    public:   
		// 类是VertexShader和PixelShader的基类。
		// 类数据的定义着色器，但不包含着色器常数和着色器纹理的实例。
		// 因此，着色器的每个实例可能是单例，通过“shaderName”标识。
		// 几何绘图涉及着色器（抽象类）和ShaderParameters（常量和纹理的实例）。
    
		// 构造函数数组必须动态地分配。着色器承担删除它们的责任。
		// 直到通过SetProgram函数提供的所有程序（用于各种型材）
		// 着色器的结构是不完整的。
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
