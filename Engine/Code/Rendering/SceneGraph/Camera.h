// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:02)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_H
#define RENDERING_SCENE_GRAPH_CAMERA_H

#include "Rendering/RenderingDll.h"

#include "Flags/CameraFlags.h"
#include "CameraFrustumData.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

RENDERING_EXPORT_SHARED_PTR(CameraImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Camera : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Camera);
        using ParentType = Object;
        using CameraSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
	    using ConstCameraSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using AxesAlignBoundingBox2D = Mathematics::AxesAlignBoundingBox2D<float>;
		using Math = Mathematics::Math<float>;
        
    public:
        Camera (bool isPerspective = true,float epsilon = Math::sm_ZeroTolerance);
        virtual ~Camera ();
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;    
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Camera); 

		float GetEpsilon() const;

        void SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector);
        
        void SetPosition (const APoint& position);
        
        void SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector);
        
        const APoint GetPosition () const;
        const AVector GetDirectionVector () const;
        const AVector GetUpVector () const;
        const AVector GetRightVector () const;
      
        const Matrix GetViewMatrix () const;
        
        bool IsPerspective () const;
        
        void SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax);
        
        void SetFrustum (const float* frustum);
        
        void SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax);
        
        const float* GetFrustum () const;
        
        const CameraFrustumData GetFrustumData () const;
 
        float GetDirectionMin () const;
        float GetDirectionMax () const;
        float GetUpMin () const;
        float GetUpMax () const;
        float GetRightMin () const;
        float GetRightMax () const;
       
        const Matrix GetProjectionMatrix () const;
       
        void SetProjectionMatrix (const Matrix& projectionMatrix);
        void SetProjectionMatrix (const APoint& p00, const APoint& p10,const APoint& p11, const APoint& p01,float nearExtrude, float farExtrude);
        
        DepthType GetDepthType () const;

        const Matrix GetProjectionViewMatrix () const;
        
        void SetPreViewMatrix (const Matrix& preViewMatrix);
        const Matrix GetPreViewMatrix () const;
        bool PreViewIsIdentity () const;
        
        void SetPostProjectionMatrix (const Matrix& postProjMatrix);
        const Matrix GetPostProjectionMatrix () const;
        bool PostProjectionIsIdentity () const;
        
        const AxesAlignBoundingBox2D ComputeBoundingAABB (int numVertices,const char* vertices,int stride,const Matrix& worldMatrix) const;

	protected:
		void SetDepthType(DepthType depthType);

    private:
		IMPL_TYPE_DECLARE(Camera);
    };
    
    CORE_TOOLS_STREAM_REGISTER(Camera);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, Camera); 
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_H
