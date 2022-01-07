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
		using APoint = Mathematics::FloatAPoint;
		using Object = CoreTools::Object;
		using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
		using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

	public:
                IKGoalImpl() noexcept;
            IKGoalImpl(const SpatialSharedPtr& target, const SpatialSharedPtr& effector, float weight = 1.0f) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const noexcept;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);
		void Link(CoreTools::ObjectLink& source);
		void Register(CoreTools::ObjectRegister& target) const;
		
		const ObjectSharedPtr GetObjectByName(const std::string& name); 
		const std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

		const ConstSpatialSharedPtr GetTarget() const noexcept;
                const ConstSpatialSharedPtr GetEffector() const noexcept;
		const APoint GetTargetPosition() const;
		const APoint GetEffectorPosition() const;

		void SetWeight(float weight) noexcept;
                float GetWeight() const noexcept;

	private:
		float m_Weight;  // ƒ¨»œ = 1
		SpatialSharedPtr m_Target;
		SpatialSharedPtr m_Effector;
	};
}

#endif // RENDERING_CONTROLLERS_IKGOAL_IMPL_H
