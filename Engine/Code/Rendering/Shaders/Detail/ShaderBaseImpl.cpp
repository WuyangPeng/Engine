// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:07)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"

#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
#include "System/Helper/PragmaWarning.h" 
#include "System/Helper/EnumCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26812)

Rendering::ShaderBaseImpl
	::ShaderBaseImpl(int numInputs,int numOutputs,int numConstants,int numSamplers)
	:m_Input{ numInputs },m_Output{ numOutputs },m_Constants{ numConstants },m_Sampler{ numSamplers },m_Profile{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderBaseImpl
	::ShaderBaseImpl()
	:m_Input{},m_Output{},m_Constants{},m_Sampler{},m_Profile{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderBaseImpl)

void Rendering::ShaderBaseImpl
	::SetInput( int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Input.SetData(index,name,type,semantic);
}

void Rendering::ShaderBaseImpl
	::SetOutput( int index, const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Output.SetData(index,name,type,semantic);
}

void Rendering::ShaderBaseImpl
	::SetConstant( int index, const string& name,int numRegistersUsed )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Constants.SetConstant(index,name,numRegistersUsed);
}

void Rendering::ShaderBaseImpl
	::SetSampler( int index, const string& name,ShaderFlags::SamplerType type )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetSampler(index,name,type);
}

void Rendering::ShaderBaseImpl
	::SetFilter( int index, ShaderFlags::SamplerFilter filter )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetFilter(index,filter);
}

void Rendering::ShaderBaseImpl
	::SetCoordinate( int index, int dimension,ShaderFlags::SamplerCoordinate coordinate )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetCoordinate(index, dimension, coordinate);
}

void Rendering::ShaderBaseImpl
	::SetLodBias( int index, float lodBias )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetLodBias(index,lodBias);
}

void Rendering::ShaderBaseImpl
	::SetAnisotropy( int index, float anisotropy )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetAnisotropy(index,anisotropy);
}

void Rendering::ShaderBaseImpl
	::SetBorderColor( int index, const Colour& borderColor )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Sampler.SetBorderColor(index,borderColor);
}

int Rendering::ShaderBaseImpl
	::GetNumInputs() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Input.GetNumber();
}

const std::string Rendering::ShaderBaseImpl
	::GetInputName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Input.GetName(index);
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseImpl
	::GetInputType( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Input.GetType(index);
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseImpl
	::GetInputSemantic( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Input.GetSemantic(index);
}

int Rendering::ShaderBaseImpl
	::GetNumOutputs() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Output.GetNumber();
}

const std::string Rendering::ShaderBaseImpl
	::GetOutputName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Output.GetName(index);
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseImpl
	::GetOutputType( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Output.GetType(index);
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseImpl
	::GetOutputSemantic( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Output.GetSemantic(index);
}

int Rendering::ShaderBaseImpl
	::GetNumConstants() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Constants.GetNumConstants();
}

const string Rendering::ShaderBaseImpl
	::GetConstantName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Constants.GetConstantName(index);
}

int Rendering::ShaderBaseImpl
	::GetNumRegistersUsed( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Constants.GetNumRegistersUsed(index);
}

int Rendering::ShaderBaseImpl
	::GetNumSamplers() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetNumSamplers();
}

const string Rendering::ShaderBaseImpl
	::GetSamplerName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetSamplerName(index);
}

Rendering::ShaderFlags::SamplerType Rendering::ShaderBaseImpl
	::GetSamplerType( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetSamplerType(index);
}

Rendering::ShaderFlags::SamplerFilter Rendering::ShaderBaseImpl
	::GetFilter( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetFilter(index);
}

Rendering::ShaderFlags::SamplerCoordinate 
	Rendering::ShaderBaseImpl
	::GetCoordinate(int index, int dimension) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetCoordinate(index, dimension);
}

float Rendering::ShaderBaseImpl
	::GetLodBias( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetLodBias(index);
}

float Rendering::ShaderBaseImpl
	::GetAnisotropy( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetAnisotropy(index);
}

Rendering::ShaderSamplerData::Colour Rendering::ShaderBaseImpl
	::GetBorderColor( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Sampler.GetBorderColor(index);
}

void Rendering::ShaderBaseImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Input.Load(source);
	m_Output.Load(source);
	m_Constants.Load(source);
	m_Sampler.Load(source);
	//source.ReadSharedPtr(m_Profile);
}

void Rendering::ShaderBaseImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_Input.Save(target);
	m_Output.Save(target);
	m_Constants.Save(target);
	m_Sampler.Save(target);
	//target.WriteSharedPtr(m_Profile);
}

int Rendering::ShaderBaseImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = m_Input.GetStreamingSize();

	size += m_Output.GetStreamingSize();
	size += m_Constants.GetStreamingSize();
	size += m_Sampler.GetStreamingSize();
	size += CORE_TOOLS_STREAM_SIZE(m_Profile);

	return size;
}

void Rendering::ShaderBaseImpl ::SetProfile(const ShaderProfileDataSharedPtr& profile) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Profile = profile;
}

const Rendering::ConstShaderProfileDataSharedPtr Rendering::ShaderBaseImpl ::GetProfile() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Profile;
}

Rendering::ShaderProfileDataSharedPtr Rendering::ShaderBaseImpl ::GetProfile() noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Profile;
}

void Rendering::ShaderBaseImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ResolveObjectSharedPtrLink(m_Profile);
}

void Rendering::ShaderBaseImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.RegisterSharedPtr(m_Profile);
}

void Rendering::ShaderBaseImpl
	::SaveShader(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numInputs = GetNumInputs();
	auto numOutputs = GetNumOutputs();
	auto numConstants = GetNumConstants();
	auto numSamplers = GetNumSamplers();
constexpr	auto numProfiles = System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles);

	manager.Write(sizeof(int), &numInputs);
	manager.Write(sizeof(int), &numOutputs);
	manager.Write(sizeof(int), &numConstants);
	manager.Write(sizeof(int), &numSamplers);
	manager.Write(sizeof(int), &numProfiles);

	for (auto i = 0; i < numInputs; ++i)
	{
		auto name = GetInputName(i);
		auto type = System::EnumCastUnderlying(GetInputType(i));
		auto semantic = System::EnumCastUnderlying(GetInputSemantic(i));

		manager.SaveStdString(name);
		manager.Write(sizeof(int), &type);
		manager.Write(sizeof(int), &semantic);
	}

	for (auto i = 0; i < numOutputs; ++i)
	{
		auto name = GetOutputName(i);
		auto type = System::EnumCastUnderlying(GetOutputType(i));
		auto semantic = System::EnumCastUnderlying(GetOutputSemantic(i));

		manager.SaveStdString(name);
		manager.Write(sizeof(int), &type);
		manager.Write(sizeof(int), &semantic);
	}

	for (auto i = 0; i < numConstants; ++i)
	{
		auto name = GetConstantName(i);
		auto numRegistersUsed = GetNumRegistersUsed(i);
		manager.SaveStdString(name);
		manager.Write(sizeof(int), &numRegistersUsed);
	}

	for (auto i = 0; i < numSamplers; ++i)
	{
		auto name = GetSamplerName(i);
		auto type = System::EnumCastUnderlying(GetSamplerType(i));
		auto filter = System::EnumCastUnderlying(GetFilter(i));
		int coord[3] { System::EnumCastUnderlying(GetCoordinate(i, 0)),System::EnumCastUnderlying(GetCoordinate(i, 1)),System::EnumCastUnderlying(GetCoordinate(i, 2)) };
		auto lodBias = GetLodBias(i);
		auto anisotropy = GetAnisotropy(i);
		auto borderColor = GetBorderColor(i);

		manager.SaveStdString(name);
		manager.Write(sizeof(int), &type);
		manager.Write(sizeof(int), &filter);
		manager.Write(sizeof(int), 3, coord);
		manager.Write(sizeof(float), &lodBias);
		manager.Write(sizeof(float), &anisotropy);
		manager.Write(sizeof(float), 4, borderColor.GetPoint().data());
	}

	const auto profile = GetProfile();

	for (auto profileIndex = 0; profileIndex < numProfiles; ++profileIndex)
	{
		manager.Write(sizeof(int), &profileIndex);
		auto programString = profile->GetProgram(profileIndex);
		manager.SaveStdString(programString);

		if (!programString.empty())
		{
			for (auto index = 0; index < numConstants; ++index)
			{
				auto baseRegister = profile->GetBaseRegister(profileIndex, index);
				manager.Write(sizeof(int), &baseRegister);
			}
			for (auto index = 0; index < numSamplers; ++index)
			{
				auto textureUnit = profile->GetTextureUnit(profileIndex, index);
				manager.Write(sizeof(int), &textureUnit);
			}
		}
	}
}

void Rendering::ShaderBaseImpl
	::LoadShader(ReadFileManager& manager,int numProfiles)
{
	RENDERING_CLASS_IS_VALID_9;

	for (auto i = 0; i < GetNumInputs(); ++i)
	{
		auto name = manager.LoadStdString();
		auto type = 0;
		auto semantic = 0;
		manager.Read(sizeof(int), &type);
		manager.Read(sizeof(int), &semantic);
		SetInput(i, name, ShaderFlags::VariableType(type), ShaderFlags::VariableSemantic(semantic));
	}

	for (auto i = 0; i < GetNumOutputs(); ++i)
	{
		auto name = manager.LoadStdString();
		auto type = 0;
		auto semantic = 0;
		manager.Read(sizeof(int), &type);
		manager.Read(sizeof(int), &semantic);
		SetOutput(i, name, ShaderFlags::VariableType(type), ShaderFlags::VariableSemantic(semantic)); 
	}

	for (auto i = 0; i < GetNumConstants(); ++i)
	{
		auto name = manager.LoadStdString();
		auto numRegistersUsed = 0;
		manager.Read(sizeof(int), &numRegistersUsed);
		SetConstant(i, name, numRegistersUsed);
	}

	for (auto i = 0; i < GetNumSamplers(); ++i)
	{
		auto name = manager.LoadStdString();
		auto type = 0;
		auto filter = 0;
		int coord[3]{ 0,0,0 };
		auto lodBias = 0.0f;
		auto anisotropy = 0.0f;
		float borderColor[4]  { 0.0f, 0.0f, 0.0f, 0.0f };

		manager.Read(sizeof(int), &type);
		manager.Read(sizeof(int), &filter);
		manager.Read(sizeof(int), 3, coord);
		manager.Read(sizeof(float), &lodBias);
		manager.Read(sizeof(float), &anisotropy);
		manager.Read(sizeof(float), 4, borderColor);
		SetSampler(i, name, ShaderFlags::SamplerType(type));
		SetFilter(i, ShaderFlags::SamplerFilter(filter));
		SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(coord[0]));
		SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate(coord[1]));
		SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate(coord[2]));
		SetLodBias(i, lodBias);
		SetAnisotropy(i, anisotropy);
		SetBorderColor(i, Colour(borderColor[0], borderColor[1], borderColor[2], borderColor[3]));
	}

	ShaderProfileDataSharedPtr profile{ std::make_shared< ShaderProfileData>(GetNumConstants(), GetNumSamplers()) };

	for (auto profileIndex = 0; profileIndex < numProfiles; ++profileIndex)
	{
		auto type = 0;
		manager.Read(sizeof(int), &type);
		RENDERING_ASSERTION_0(0 <= type && type < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "Œﬁ–ßprofile");

		if (0 <= type && type < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles))
		{
			auto programName = manager.LoadStdString();
			profile->SetProgram(profileIndex, programName);

			if (!programName.empty())
			{			
				for (auto index = 0; index < GetNumConstants(); ++index)
				{
					auto baseRegister = 0;
					manager.Read(sizeof(int), &baseRegister);
					profile->SetBaseRegister(profileIndex, index, baseRegister);
				}

				for (auto index = 0; index < GetNumSamplers(); ++index)
				{
					auto textureUnit = 0;
					manager.Read(sizeof(int), &textureUnit);
					profile->SetTextureUnit(profileIndex, index, textureUnit);
				}
			}
		}	
	}

	SetProfile(profile);
}
#include STSTEM_WARNING_POP