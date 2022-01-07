// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:18)

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
		Colour m_Emissive;  // Ĭ��: (0,0,0,1)
		Colour m_Ambient;   // Ĭ��: (0,0,0,1)		
	
		// ���ϵ�alphaʹ��m_Diffuse��alphaͨ��
		Colour m_Diffuse;   // Ĭ��: (0,0,0,1)		

		// ���ϵľ���ָ��ʹ��m_Specular��alphaͨ��
		Colour m_Specular;  // Ĭ��: (0,0,0,0)
	};
}

#endif // RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H
