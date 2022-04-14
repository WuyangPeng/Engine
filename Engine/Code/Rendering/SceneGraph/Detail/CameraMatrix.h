///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 11:05)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
#define RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H

#include "CameraFrustum.h"
#include "WorldCoordinateFrame.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

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
        explicit CameraMatrix(const WorldCoordinateFrame& worldCoordinateFrame, const CameraFrustum& cameraFrustum, float epsilon = Math::GetZeroTolerance());
        explicit CameraMatrix(float epsilon);

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
        NODISCARD Matrix GetProjectionMatrix() const noexcept;

        // ֧�ָ߼�Ч����
        // ��һ�����������������κ�ͶӰ����
        // �ڶ�������ָ��һ��͹�ı����ӿڡ�
        // ��������������ϵ�Ҷ����ӵ�۲�����ʱ��˳��
        // ƽ�����ı����ڹ۲�ƽ��,��һ�������족ֵΪ1��
        // nearExtrudeֵ��(0,infinity)��
        // ��ָ���������ӵ㵽�۲�ƽ���������ε���ͼ������Ľ�ƽ�档
        // farExtrudeֵ��(nearExtrude,infinity)��
        // ��ָ���������ӵ㵽�۲�ƽ���������ε���ͼ�������Զƽ�档
        void SetProjectionMatrix(const Matrix& aProjectionMatrix);
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        NODISCARD DepthType GetDepthType() const noexcept;

        void SetDepthType(DepthType aDepthType);

        // ����ͶӰ��ͼ�����ǳ��õ�Ƭ����ɫ������ȥת��ģ�Ϳռ����ݵ��ü��ռ����ݡ�
        // Ϊ�˱����ظ�����ÿ�����ζ����ͶӰ����,�ڸ����д洢��ά����
        NODISCARD Matrix GetProjectionViewMatrix() const noexcept;

        // Ԥ������Ӧ������ģ�Ͷ�����֮����ͼ����֮ǰ��
        // ����ת�����������ķ��䡣Ĭ��ֵΪ��λ����
        void SetPreViewMatrix(const Matrix& aPreViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        bool PreViewIsIdentity() const noexcept;

        // ��ͶӰ�������ڿռ�ת������Ⱦ���ͼ��ķ��䡣Ĭ��ֵΪ��λ����
        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        // ����ͶӰ������ƽ��ͷ��ı仯��
        void OnFrustumChange(const CameraFrustum& cameraFrustum);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD const CameraFrustum& GetCameraFrustum() const noexcept;
        NODISCARD const WorldCoordinateFrame& GetWorldCoordinateFrame() const noexcept;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void SetPosition(const APoint& position);

        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        NODISCARD float GetEpsilon() const noexcept;

    private:
        void OnFrustumChange();

        // �����ͶӰ����ͶӰ������ͼ����Ԥ������Ľ��
        void UpdateProjectionViewMatrix();

    private:
        WorldCoordinateFrame worldCoordinateFrame;
        CameraFrustum cameraFrustum;

        // �������ͶӰ����
        // ͶӰ���󱻴洢Ϊ�ҳ�����,projMatrix * someVector4��
        std::array<Matrix, System::EnumCastUnderlying(DepthType::Quantity)> projectionMatrix;

        // ͶӰ����ͼ����ĳ˻��������post-projection��/��pre-view����Щ�����ǵ�λ����ʱ��
        std::array<Matrix, System::EnumCastUnderlying(DepthType::Quantity)> projectionViewMatrix;

        // �������preview����
        Matrix preViewMatrix;
        bool preViewIsIdentity;

        // �������postprojection����
        Matrix postProjectionMatrix;
        bool postProjectionIsIdentity;

        // ��������������͡�ֵ�ڹ��캯��ʱ����ʼ��ΪCAMERA_MANAGE_SINGLETON.GetDepthType()��
        // ����������д洢��ֵ��
        // ������Projector����������ͺʹ洢��,��Ϊ�������Ҫһ��ͶӰ�ǵ����͵���ƥ��ͼ��API���͡�
        DepthType depthType;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
