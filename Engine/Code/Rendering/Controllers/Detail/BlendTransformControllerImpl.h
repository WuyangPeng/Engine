// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:09)

#ifndef RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h" 

#include "Rendering/Controllers/TransformController.h"

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class ObjectLink;
	class ObjectRegister;
	class Object;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE BlendTransformControllerImpl
	{
	public:
		using ClassType = BlendTransformControllerImpl;
		using Object = CoreTools::Object;
		using APoint = Mathematics::APointF;
		using Matrix = Mathematics::MatrixF;
		using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
		using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

	public:		
		BlendTransformControllerImpl() noexcept;
		BlendTransformControllerImpl(const TransformControllerSharedPtr& firstController,const TransformControllerSharedPtr& secondController,
                                             bool rotationScaleMatrices, bool geometricRotation = false, bool geometricScale = false) noexcept;

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
		
 		// 权重w是一个数字的量0 <= w <= 1。
                const ConstTransformControllerSharedPtr GetFirstController() const noexcept;
                const ConstTransformControllerSharedPtr GetSecondController() const noexcept;
                bool IsRotationScaleMatrices() const noexcept;
                void SetWeight(float weight) noexcept;
                float GetWeight() const noexcept;

		bool IsGeometricRotation() const noexcept;
                bool IsGeometricScale() const noexcept;

		void  SetObject(ControllerInterface* object);
		bool Update(double applicationTime);

		const APoint GetBlendTranslate() const;
		const Matrix GetBlendQuaternion() const;
		const APoint GetBlendScale() const;
		const Matrix GetMatrix() const;
	
	 private:
		 TransformControllerSharedPtr m_FirstController;
		 TransformControllerSharedPtr m_SecondController;
		 float m_Weight;
		 bool m_RotationScaleMatrices;
		 bool m_GeometricRotation;
		 bool m_GeometricScale;
	};
}

#endif // RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H
