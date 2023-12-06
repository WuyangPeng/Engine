/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/27 11:16)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_H
#define RENDERING_SCENE_GRAPH_CAMERA_H

#include "Rendering/RenderingDll.h"

#include "PickLine.h"
#include "ViewVolume.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Camera, CameraImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Camera : public ViewVolume
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Camera);
        using ParentType = ViewVolume;

        using CameraSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static CameraSharedPtr Create(bool isPerspective, DepthType depthType, float epsilon);

        Camera(bool isPerspective, DepthType depthType, float epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Camera);

        void SetPreViewMatrix(const Matrix& preViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        /// ֧���Ӳ�ͶӰ��ָ��һ��͹�ı����ӿڡ�
        /// ��Щ���������������У����Ҵ��۵�۲�ʱ����ʱ��˳�����С�
        /// �ı��ε�ƽ������ͼƽ�棬��"extrude"ֵΪ1��
        /// nearExtrudeֵ��(0,�����)�У���ָ���˴��ӵ㵽������������ͼ����������ͼƽ��ķ�����
        /// farExtrudeֵΪ(nearExtrude,�����)����ָ���˷�����������ͼ�����Զ����ӵ�ķ�����
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        /// ����������Ļ����(x,y)���ӿں���Ӱ������ʰȡ�ߡ�
        /// �����ԭ�㡱�����λ�ã��������ǵ�λ����ʸ������Ϊ�������ꡣ
        /// ���(x,y)���ӿ��У��򷵻�ֵΪtrue��
        NODISCARD PickLine GetPickLine(int viewX, int viewY, int viewWidth, int viewHigh, int x, int y) const;

    protected:
        void UpdateProjectionViewMatrix() noexcept override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Camera);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Camera);
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_H
