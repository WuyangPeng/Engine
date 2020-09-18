// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 19:12)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CameraMatrix.h"
#include "WorldCoordinateFrame.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2D.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraImpl
    {
    public:
		using ClassType = CameraImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
		using AxesAlignBoundingBox2D = Mathematics::AxesAlignBoundingBox2D<float>;
        using HomogeneousPoint = Mathematics::HomogeneousPoint<float>;
        using Math = Mathematics::Math<float>;
        
    public:
        explicit CameraImpl (bool isPerspective,float epsilon = Math::GetZeroTolerance());
        explicit CameraImpl(float epsilon = Math::GetZeroTolerance())  ;
        
		CLASS_INVARIANT_DECLARE;

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

        void SetPostProjectionMatrix (const Matrix& postProjMatrix) ;
        const Matrix GetPostProjectionMatrix() const noexcept;
        bool PostProjectionIsIdentity() const noexcept;

        // 对一组顶点计算轴对齐矩形包围盒在正则化显示空间,[-1,1]x[-1,1]。
        // 输入“顶点”是“float”的值三元组的指针,每个三元组代表一个顶点。
        // stride是从一个顶点第一位置的数通道到下一个顶点的第一个位置的通道的字节数。
        // 如果顶点是连续封装,stride为3 * sizeof(float)。
        // 顶点是在模型视图空间。输入“worldMatrix”转换模型视图空间到世界空间。
     
        const AxesAlignBoundingBox2D ComputeBoundingAABB (int numVertices,const char* vertices,int stride,const Matrix& worldMatrix) const;
        
        void Load (BufferSource& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;

		void SetDepthType(DepthType depthType)  ;
        
    private:     
        CameraMatrix m_CameraMatrix;     
    };
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
