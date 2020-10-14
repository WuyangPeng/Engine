// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:01)

#ifndef RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <array>
#include <string>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE SingleShaderSamplerDataImpl
	{	
	public:
		using ClassType = SingleShaderSamplerDataImpl;
		using Colour = Colour<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		SingleShaderSamplerDataImpl(); 

		CLASS_INVARIANT_DECLARE;
		
		void SetSampler (const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (float lodBias);
		void SetAnisotropy (float anisotropy);
		void SetBorderColor (const Colour& borderColor);

		const std::string GetSamplerName () const;
		ShaderFlags::SamplerType GetSamplerType () const;
		ShaderFlags::SamplerFilter GetFilter () const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int dimension) const;
		float GetLodBias () const;
		float GetAnisotropy () const;
		Colour GetBorderColor () const;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
		
	private:	
		constexpr static auto sm_SamplerCoordinateSize = 3;

	private:
		std::string m_SamplerName;
		ShaderFlags::SamplerType m_SamplerType;
		ShaderFlags::SamplerFilter m_Filter;   
		std::array<ShaderFlags::SamplerCoordinate, sm_SamplerCoordinateSize> m_Coordinate;
		float m_LodBias;
		float m_Anisotropy;
		Colour m_BorderColor;
	};
}

#endif // RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H
