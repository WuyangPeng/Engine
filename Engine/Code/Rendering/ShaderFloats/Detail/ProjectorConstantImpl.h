// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:45)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Projector.h"

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
	class RENDERING_HIDDEN_DECLARE ProjectorConstantImpl
	{
	public:
		using ClassType = ProjectorConstantImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using Object = CoreTools::Object;
		using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
		using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;

	public: 
		explicit ProjectorConstantImpl(const ProjectorSmartPointer& projector);
		ProjectorConstantImpl();
		virtual ~ProjectorConstantImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	
		virtual void Load(BufferSource& source);
		virtual void Save(BufferTarget& target) const;
		virtual int GetStreamingSize() const;
		void Link(ObjectLink& source);
		void Register(ObjectRegister& target) const;

		const ObjectSmartPointer GetObjectByName(const std::string& name); 
		const std::vector<ObjectSmartPointer> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSmartPointer> GetAllConstObjectsByName(const std::string& name) const;

		const ConstProjectorSmartPointer GetProjector() const;
   
	private:
		ProjectorSmartPointer m_Projector;
	};
}

#endif // RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H
