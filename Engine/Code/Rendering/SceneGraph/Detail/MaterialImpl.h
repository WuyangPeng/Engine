// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 19:18)

#ifndef RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H
#define RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h" 

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE MaterialImpl
	{
	public:
		using ClassType = MaterialImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using Colour = Colour<float>;

	public:
		MaterialImpl();
		MaterialImpl(const Colour& emissive, const Colour& ambient,const Colour& diffuse, const Colour& specular);
 
		CLASS_INVARIANT_DECLARE;

		void Load(CoreTools::BufferSource& source);
		void Save(CoreTools::BufferTarget& target) const;
		int GetStreamingSize() const;

		const Colour GetEmissive() const;  
		const Colour GetAmbient() const;
		const Colour GetDiffuse() const;
		const Colour GetSpecular() const;

		void SetEmissive(const Colour& emissive);
		void SetAmbient(const Colour& ambient);
		void SetDiffuse(const Colour& diffuse);
		void SetSpecular(const Colour& specular);

		float GetAlpha() const;
		float GetSpecularExponent() const;

	private:
		Colour m_Emissive;  // 默认: (0,0,0,1)
		Colour m_Ambient;   // 默认: (0,0,0,1)		
	
		// 材料的alpha使用m_Diffuse的alpha通道
		Colour m_Diffuse;   // 默认: (0,0,0,1)		

		// 材料的镜面指数使用m_Specular的alpha通道
		Colour m_Specular;  // 默认: (0,0,0,0)
	};
}

#endif // RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H
