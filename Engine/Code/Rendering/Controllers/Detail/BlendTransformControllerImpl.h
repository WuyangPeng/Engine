// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:09)

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
		using APoint = Mathematics::APointf;
		using Matrix = Mathematics::Matrixf;
		using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
		using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;

	public:		
		BlendTransformControllerImpl();
		BlendTransformControllerImpl(const TransformControllerSmartPointer& firstController,const TransformControllerSmartPointer& secondController,
									 bool rotationScaleMatrices,bool geometricRotation = false,bool geometricScale = false);

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
		
 		// Ȩ��w��һ�����ֵ���0 <= w <= 1��
		const ConstTransformControllerSmartPointer GetFirstController() const;
		const ConstTransformControllerSmartPointer GetSecondController() const;
		bool IsRotationScaleMatrices() const;
		void SetWeight (float weight);
		float GetWeight () const;

		bool IsGeometricRotation() const;
		bool IsGeometricScale() const;

		void  SetObject(ControllerInterface* object);
		bool Update(double applicationTime);

		const APoint GetBlendTranslate() const;
		const Matrix GetBlendQuaternion() const;
		const APoint GetBlendScale() const;
		const Matrix GetMatrix() const;
	
	 private:
		 TransformControllerSmartPointer m_FirstController;
		 TransformControllerSmartPointer m_SecondController;
		 float m_Weight;
		 bool m_RotationScaleMatrices;
		 bool m_GeometricRotation;
		 bool m_GeometricScale;
	};
}

#endif // RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H
