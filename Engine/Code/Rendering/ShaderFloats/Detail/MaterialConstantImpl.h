// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 16:44)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Material.h"

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
	class RENDERING_HIDDEN_DECLARE MaterialConstantImpl
	{
	public:
		using ClassType = MaterialConstantImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using Object = CoreTools::Object;
		using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
		using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

	public: 
		explicit MaterialConstantImpl(const MaterialSharedPtr& material) noexcept;
            MaterialConstantImpl() noexcept;

		CLASS_INVARIANT_DECLARE;
	
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		const ObjectSharedPtr GetObjectByName(const std::string& name); 
		const std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

		const ConstMaterialSharedPtr GetMaterial() const;
   
	private:
		MaterialSharedPtr m_Material;
	};
}

#endif // RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_IMPL_H
