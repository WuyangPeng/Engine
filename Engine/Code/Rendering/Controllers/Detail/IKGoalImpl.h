// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:12)

#ifndef RENDERING_CONTROLLERS_IKGOAL_IMPL_H
#define RENDERING_CONTROLLERS_IKGOAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Spatial.h"

#include <vector>
#include <string>

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class ObjectLink;
	class ObjectRegister;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE IKGoalImpl
	{
	public:
		using ClassType = IKGoalImpl;
		using APoint = Mathematics::APointf;
		using Object = CoreTools::Object;
		using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
		using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;

	public:
                IKGoalImpl() noexcept;
            IKGoalImpl(const SpatialSmartPointer& target, const SpatialSmartPointer& effector, float weight = 1.0f) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);
		void Link(CoreTools::ObjectLink& source);
		void Register(CoreTools::ObjectRegister& target) const;
		
		const ObjectSmartPointer GetObjectByName(const std::string& name); 
		const std::vector<ObjectSmartPointer> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSmartPointer> GetAllConstObjectsByName(const std::string& name) const;

		const ConstSpatialSmartPointer GetTarget() const noexcept;
                const ConstSpatialSmartPointer GetEffector() const noexcept;
		const APoint GetTargetPosition() const;
		const APoint GetEffectorPosition() const;

		void SetWeight(float weight) noexcept;
                float GetWeight() const noexcept;

	private:
		float m_Weight;  // ƒ¨»œ = 1
		SpatialSmartPointer m_Target;
		SpatialSmartPointer m_Effector;
	};
}

#endif // RENDERING_CONTROLLERS_IKGOAL_IMPL_H
