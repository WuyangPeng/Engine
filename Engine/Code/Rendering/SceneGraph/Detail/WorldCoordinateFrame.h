/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:53)

#ifndef RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
#define RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WorldCoordinateFrame
    {
    public:
        using ClassType = WorldCoordinateFrame;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        WorldCoordinateFrame() noexcept;
        explicit WorldCoordinateFrame(float epsilon);

        CLASS_INVARIANT_DECLARE;

        /// ���������ϵ�������������ꡣĬ������ϵ{P;D,U,R}���������������У�����
        /// Ĭ�� position  P = (0, 0,  0; 1)
        /// Ĭ�� direction D = (0, 0, -1; 0)
        /// Ĭ�� up        U = (0, 1,  0; 0)
        /// Ĭ�� right     R = (1, 0,  0; 0)
        /// ��{D,U,R}��Ҫ��һ��������������
        void SetPosition(const APoint& aPosition);

        void SetAxes(const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector);

        void SetFrame(const APoint& aPosition, const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        /// ��������ϵ����ͼ����
        /// ���D = (d0,d1,d2),U = (u0,u1,u2),��R = (r0,r1,r2),
        /// ��ͼ����Ϊ
        ///   +-                     -+
        ///   | r0  r1  r2  -Dot(R,P) |
        ///   | u0  u1  u2  -Dot(U,P) |
        ///   | d0  d1  d2  -Dot(D,P) |
        ///   |  0   0   0          1 |
        ///   +-                     -+
        /// ��������MATHEMATICS_USE_MATRIX_VECTOR������ͼ�����ҳ���������viewMat*vector4��
        /// ��δ����MATHEMATICS_USE_MATRIX_VECTOR������ͼ���������������vector4*viewMat����ʹ����ʾ�����ת�á�
        /// MATHEMATICS_USE_MATRIX_VECTORԼ��������ͼ����Ϊ
        ///            +-            -+
        ///            | r0 u0 d0 p0 |
        ///   V^{-1} = | r1 u1 d1 p1 |
        ///            | r2 u2 d2 p1 |
        ///            |  0  0  0  1 |
        ///            +-           -+
        /// ��X = (x0,x1,x2,1)������
        ///   X = P + y0*R + y1*U + y2*D,
        /// ����y0 = Dot(R,X-P), y1 = Dot(U,X-P), �� y2 = Dot(D,X-P)
        /// ʹ��MATHEMATICS_USE_MATRIX_VECTORԼ�������Y = (y0,y1,y2,1)����Y = V*X��
        /// ����V����ͼ����
        NODISCARD Matrix GetViewMatrix() const noexcept;
        NODISCARD Matrix GetInverseViewMatrix() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // ����֡���ĺ����ͼ����Ȼ�����ͶӰ��ͼ����
        void OnFrameChange();

    private:
        // ��������ϵ��
        APoint position;
        AVector directionVector;
        AVector upVector;
        AVector rightVector;

        /// ��������ϵ����ͼ����V����
        /// �洢˳��ȡ�����Ƿ�����MATHEMATICS_USE_MATRIX_VECTOR��
        /// ��һ������������ͼ����(V^{-1})��
        Matrix viewMatrix;
        Matrix inverseViewMatrix;

#ifdef RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        /// ����ʹ��������������ƣ�ͨ��RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE����
        /// ��������������ȷ�����Ŀ�ܻ�������ֵ����������б�Ŀ�ܡ�
        bool validateCoordinateFrame;

#endif  // RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
