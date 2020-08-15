// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 19:14)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
#define RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "CameraFrustum.h"
#include "WorldCoordinateFrame.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraMatrix
    {
    public:
        using ClassType = CameraMatrix;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using Math = Mathematics::Math<float>;

    public:
        explicit CameraMatrix(const WorldCoordinateFrame& worldCoordinateFrame, const CameraFrustum& cameraFrustum, float epsilon = Math::sm_ZeroTolerance);
        explicit CameraMatrix(float epsilon = Math::sm_ZeroTolerance);

        CLASS_INVARIANT_DECLARE;

        // ƽ��ͷ���ֵ��N (near), F (far), B (bottom), T (top),
        // L (left), �� R (right).  ���־������£�
        //
        // ͸��, ��� [0,1]
        //   +-                                               -+
        //   | 2*N/(R-L)  0           -(R+L)/(R-L)  0          |
        //   | 0          2*N/(T-B)   -(T+B)/(T-B)  0          |
        //   | 0          0           F/(F-N)       -N*F/(F-N) |
        //   | 0          0           1             0          |
        //   +-                                               -+
        //
        // ͸��, ��� [-1,1]
        //   +-                                                 -+
        //   | 2*N/(R-L)  0           -(R+L)/(R-L)  0            |
        //   | 0          2*N/(T-B)   -(T+B)/(T-B)  0            |
        //   | 0          0           (F+N)/(F-N)   -2*F*N/(F-N) |
        //   | 0          0           1             0
        //   +-                                                 -+
        //
        // ����, ��� [0,1]
        //   +-                                       -+
        //   | 2/(R-L)  0  0              -(R+L)/(R-L) |
        //   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        //   | 0        0        1/(F-N)  -N/(F-N)  0  |
        //   | 0        0        0        1            |
        //   +-                                       -+
        //
        // ����, ��� [-1,1]
        //   +-                                       -+
        //   | 2/(R-L)  0        0        -(R+L)/(R-L) |
        //   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        //   | 0        0        2/(F-N)  -(F+N)/(F-N) |
        //   | 0        0        0        1            |
        //   +-                                       -+
        //
        // ͶӰ�����ҳ�����,projMat * vector4��

        // ���ؾ����ֵȡ����DepthType��IsPerspective��
        const Matrix GetProjectionMatrix() const noexcept;

        // ֧�ָ߼�Ч����
        // ��һ�����������������κ�ͶӰ����
        // �ڶ�������ָ��һ��͹�ı����ӿڡ�
        // ��������������ϵ�Ҷ����ӵ�۲�����ʱ��˳��
        // ƽ�����ı����ڹ۲�ƽ��,��һ�������족ֵΪ1��
        // nearExtrudeֵ��(0,infinity)��
        // ��ָ���������ӵ㵽�۲�ƽ���������ε���ͼ������Ľ�ƽ�档
        // farExtrudeֵ��(nearExtrude,infinity)��
        // ��ָ���������ӵ㵽�۲�ƽ���������ε���ͼ�������Զƽ�档
        void SetProjectionMatrix(const Matrix& projectionMatrix);
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        DepthType GetDepthType() const noexcept;

        void SetDepthType(DepthType depthType);

        // ����ͶӰ��ͼ�����ǳ��õ�Ƭ����ɫ������ȥת��ģ�Ϳռ����ݵ��ü��ռ����ݡ�
        // Ϊ�˱����ظ�����ÿ�����ζ����ͶӰ����,�ڸ����д洢��ά����
        const Matrix GetProjectionViewMatrix() const noexcept;

        // Ԥ������Ӧ������ģ�Ͷ�����֮����ͼ����֮ǰ��
        // ����ת�����������ķ��䡣Ĭ��ֵΪ��λ����
        void SetPreViewMatrix(const Matrix& preViewMatrix)  ;
        const Matrix GetPreViewMatrix() const noexcept;
        bool PreViewIsIdentity() const noexcept;

        // ��ͶӰ�������ڿռ�ת������Ⱦ���ͼ��ķ��䡣Ĭ��ֵΪ��λ����
        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        const Matrix GetPostProjectionMatrix() const noexcept;
        bool PostProjectionIsIdentity() const noexcept;

        // ����ͶӰ������ƽ��ͷ��ı仯��
        void OnFrustumChange(const CameraFrustum& cameraFrustum);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        int GetStreamingSize() const;

        const CameraFrustum& GetCameraFrustum() const noexcept;
        const WorldCoordinateFrame& GetWorldCoordinateFrame() const noexcept;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void SetPosition(const APoint& position)  ;

        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        float GetEpsilon() const noexcept;

    private:
        void OnFrustumChange();

        // �����ͶӰ����ͶӰ������ͼ����Ԥ������Ľ��
        void UpdateProjectionViewMatrix();

    private:
        WorldCoordinateFrame m_WorldCoordinateFrame;
        CameraFrustum m_CameraFrustum;

        // �������ͶӰ����
        // ͶӰ���󱻴洢Ϊ�ҳ�����,projMatrix * someVector4��
        Matrix m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::Quantity)];

        // ͶӰ����ͼ����ĳ˻��������post-projection��/��pre-view����Щ�����ǵ�λ����ʱ��
        Matrix m_ProjectionViewMatrix[System::EnumCastUnderlying(DepthType::Quantity)];

        // �������preview����
        Matrix m_PreViewMatrix;
        bool m_PreViewIsIdentity;

        // �������postprojection����
        Matrix m_PostProjectionMatrix;
        bool m_PostProjectionIsIdentity;

        // ��������������͡�ֵ�ڹ��캯��ʱ����ʼ��ΪCAMERA_MANAGE_SINGLETON.GetDepthType()��
        // ����������д洢��ֵ��
        // ������Projector����������ͺʹ洢��,��Ϊ�������Ҫһ��ͶӰ�ǵ����͵���ƥ��ͼ��API���͡�
        DepthType m_DepthType;

        float m_Epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
