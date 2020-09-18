// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:43)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Light.h"

#include <vector>
#include <string>
 
namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class Object;
	class ObjectLink;
	class ObjectRegister;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE LightConstantImpl
	{
	public:
		using ClassType = LightConstantImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using Object = CoreTools::Object;
		using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
		using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;
 
	public: 
		explicit LightConstantImpl(const LightSmartPointer& light);
		LightConstantImpl();

		CLASS_INVARIANT_DECLARE;
	
		void Load(BufferSource& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		void Link(ObjectLink& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		const ObjectSmartPointer GetObjectByName(const std::string& name); 
		const std::vector<ObjectSmartPointer> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSmartPointer> GetAllConstObjectsByName(const std::string& name) const;
 
		const ConstLightSmartPointer GetLight() const;
   
	private:
		LightSmartPointer m_Light;
	};
}

#endif // RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H
