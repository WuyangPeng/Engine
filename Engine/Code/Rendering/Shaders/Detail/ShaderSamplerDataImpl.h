// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:53)

#ifndef RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/SingleShaderSamplerData.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderSamplerDataImpl
	{	
	public:
		using ClassType = ShaderSamplerDataImpl;
		using Colour = Colour<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		ShaderSamplerDataImpl() noexcept;
		explicit ShaderSamplerDataImpl(int numSamplers);

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);	
		
		void SetSampler (int index, const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (int index, ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int index, int dimension,ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (int index, float lodBias);
		void SetAnisotropy (int index, float anisotropy);
		void SetBorderColor (int index, const Colour& borderColor);

		int GetNumSamplers () const;
		const std::string GetSamplerName (int index) const;
		ShaderFlags::SamplerType GetSamplerType (int index) const;
		ShaderFlags::SamplerFilter GetFilter (int index) const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int index, int dimension) const;
		float GetLodBias (int index) const;
		float GetAnisotropy (int index) const;
		Colour GetBorderColor (int index) const;

		void Load(CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;
		
	private:		
		std::vector<SingleShaderSamplerData> m_SingleShaderSamplerData; 
	};
}

#endif // RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H
