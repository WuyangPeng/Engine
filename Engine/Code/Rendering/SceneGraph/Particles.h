// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 11:31)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_H
#define RENDERING_SCENE_GRAPH_PARTICLES_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "TrianglesMesh.h"
EXPORT_SHARED_PTR(Rendering, ParticlesImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class Culler;

    class RENDERING_DEFAULT_DECLARE Particles : public TrianglesMesh
    {
    public:
        void Swap(Particles& rhs) noexcept;
       
           public:
               TYPE_DECLARE(Particles);
               using ClassShareType = CoreTools::CopyUnsharedClasses;
               ~Particles() noexcept;
               Particles(const Particles& rhs);
               Particles& operator=(const Particles& rhs);
               Particles(Particles&& rhs) noexcept;
               Particles& operator=(Particles&& rhs) noexcept;
        using ParentType = TrianglesMesh;
        using ParticlesSharedPtr = std::shared_ptr<ClassType>;
        using ConstParticlesSharedPtr = std::shared_ptr<ClassType>;

    public:
        // VertexFormat����������3Ԫ��λ�á�
        // Ҳ������2Ԫ�������������ͨ���㣬
        // ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
        // vertexbufferԪ�ص�����������4�ı�����
        // Ԫ�ص�������������1/4 vertexbufferԪ�صĸ�����
        // �������������Զ����ɵġ�
        // 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
        Particles(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize,
                  const std::vector<APoint>& positions, const std::vector<float>& sizes, float sizeAdjust);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

        int GetNumParticles() const;
        const APoint GetPosition(int index) const;
        float GetSize(int index) const;
        void SetSizeAdjust(float sizeAdjust) ;
        float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const APoint& position);
        void SetSize(int index, float size);

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int numActive);
        int GetNumActive() const noexcept;

        // �����ǹ���ƣ�������Ծ�ͷ��
        void GenerateParticles(const ConstCameraSharedPtr& camera);

          ControllerInterfaceSharedPtr Clone() const override;

          void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        void InitIndexBuffer(int indexSize);
        void InitTextureCoord();

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Particles);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(  Particles);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SCENE_GRAPH_PARTICLES_H
