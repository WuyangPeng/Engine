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


EXPORT_SHARED_PTR(Rendering, CameraImpl, RENDERING_DEFAULT_DECLARE);
 

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Camera : public CoreTools::Object
    {
    public:
        void Swap(Camera& rhs) noexcept;

    public:
        TYPE_DECLARE(Camera);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~Camera() noexcept = default;
        Camera(const Camera& rhs);
        Camera& operator=(const Camera& rhs);
        Camera(Camera&& rhs) noexcept;
        Camera& operator=(Camera&& rhs) noexcept;
        using ParentType = Object;
        using CameraSharedPtr = std::shared_ptr<ClassType>;
	    using ConstCameraSharedPtr = std::shared_ptr<ClassType>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using AxesAlignBoundingBox2D = Mathematics::AxesAlignBoundingBox2<float>;
		using Math = Mathematics::Math<float>;
        
    public:
        Camera (bool isPerspective = true,float epsilon = Math::GetZeroTolerance());

            ObjectInterfaceSharedPtr CloneObject() const override;
		CLASS_INVARIANT_OVERRIDE_DECLARE;    
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Camera); 

		float GetEpsilon() const noexcept;

        void SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector);
        
        void SetPosition (const APoint& position);
        
        void SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector);
        
        const APoint GetPosition () const;
        const AVector GetDirectionVector () const;
        const AVector GetUpVector () const;
        const AVector GetRightVector () const;
      
        const Matrix GetViewMatrix () const;
        
        bool IsPerspective() const noexcept;
        
        void SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax);
        
        void SetFrustum (const float* frustum);
        
        void SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax);
        
        const float* GetFrustum() const noexcept;
        
        const CameraFrustumData GetFrustumData() const noexcept;
 
        float GetDirectionMin() const noexcept;
        float GetDirectionMax() const noexcept;
        float GetUpMin() const noexcept;
        float GetUpMax() const noexcept;
        float GetRightMin() const noexcept;
        float GetRightMax() const noexcept;
       
        const Matrix GetProjectionMatrix() const noexcept;
       
        void SetProjectionMatrix (const Matrix& projectionMatrix);
        void SetProjectionMatrix (const APoint& p00, const APoint& p10,const APoint& p11, const APoint& p01,float nearExtrude, float farExtrude);
        
        DepthType GetDepthType() const noexcept;

        const Matrix GetProjectionViewMatrix() const noexcept;
        
        void SetPreViewMatrix(const Matrix& preViewMatrix)  ;
        const Matrix GetPreViewMatrix() const noexcept;
        bool PreViewIsIdentity() const noexcept;
        
        void SetPostProjectionMatrix (const Matrix& postProjMatrix);
        const Matrix GetPostProjectionMatrix() const noexcept;
        bool PostProjectionIsIdentity() const noexcept;
        
        const AxesAlignBoundingBox2D ComputeBoundingAABB (int numVertices,const char* vertices,int stride,const Matrix& worldMatrix) const;

	protected:
		void SetDepthType(DepthType depthType);

    private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)  
    CORE_TOOLS_STREAM_REGISTER(Camera);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( Camera); 
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_H
