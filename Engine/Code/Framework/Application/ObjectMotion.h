// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Mathematics/Algebra/Matrix.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(ObjectMotionImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ObjectMotion
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ObjectMotion);
		using SpatialSmartPointer = Rendering::SpatialSmartPointer;
		using ConstSpatialSmartPointer = Rendering::ConstSpatialSmartPointer;
		using ConstCameraSmartPointer = Rendering::ConstCameraSmartPointer;
		using Matrix = Mathematics::Matrixf;
		using AVector = Mathematics::AVectorf;
		using Transform = Rendering::Transform;
		
	public:
		explicit ObjectMotion(const SpatialSmartPointer& motionObject);
	
		CLASS_INVARIANT_DECLARE;

		bool MoveObject (float rotationSpeed);
		void RotateTrackBall(const ConstCameraSmartPointer& camera);

        void SetDoRoll(int value);
        void SetDoYaw(int value);
        void SetDoPitch(int value);
		void SetTrackBallDow(bool value);
		bool GetTrackBallDow() const;
   
        void SetBeginTrack(float xTrack,float yTrack);
        void SetEndTrack(float xTrack,float yTrack);
		void SetSaveRotate();	     

		const Transform GetMotionObjectLocalTransform() const;

	private:
		IMPL_TYPE_DECLARE(ObjectMotion);
	};
}

#endif // FRAMEWORK_APPLICATION_OBJECT_MOTION_H



	