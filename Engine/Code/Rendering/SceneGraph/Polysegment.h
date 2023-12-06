///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_POLYSEGMENT_H
#define RENDERING_SCENE_GRAPH_POLYSEGMENT_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Polysegment : public Visual
    {
    public:
        using ClassType = Polysegment;
        using ParentType = Visual;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using PolysegmentSharedPtr = std::shared_ptr<ClassType>;
        using ConstPolysegmentSharedPtr = std::shared_ptr<ClassType>;

    public:
        // ���'contiguous'��'true'����ö����γ�������������polysegment��ÿ�������Ķ��������߶����ӡ�
        // ���磬{ V0, V1, V2, V3 } ��ʽ�߶�<V0, V1>, <V1, V2>, and <V2, V3>��
        // ���������һ����յ�polysegment�����붥�㻺���������һ��Ԫ�ر����ǵ�һ��Ԫ�صĸ�����
        // ���磬{V0, V1, V2, V3 = V0}�γɾ����߶ε�������<V0, V1>, <V1, V2>, and <V2, V0>��
        // ���'contiguous'��'false'�������γ�һ��Ͽ����߶Ρ�
        // ���磬{V0, V1, V2, V3}��ʽ�߶�<V0, V1>�� <V2, V3>��
        // ����������£����붥�㻺�����������ż����Ŀ��Ԫ�ء�
        Polysegment(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, bool contiguous);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Polysegment);

        // ����Ӧ�ó���ָ��������С��polysegment���߶��������ڻ��ơ�
        // ����һ��������polysegment��0 <= numSegments <= numVertices - 1��
        // ���ڲ��ཻ���߶Σ�0 <= numSegments <= numVertices / 2��
        NODISCARD int GetMaxNumSegments() const noexcept;
        void SetNumSegments(int aNumSegments) noexcept;
        NODISCARD int GetNumSegments() const noexcept;

        // ��'contiguous'��'true'������polysegment�������߶ε����С�
        // ����һ�鲻�ཻ��ʱ��'contiguous'��'false'��
        NODISCARD bool GetContiguous() const noexcept;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        // ��ǰ��߶ε�����
        int numSegments;

        // �������������ཻ���߶�
        bool contiguous;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Polysegment);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Polysegment);
}

#endif  // RENDERING_SCENE_GRAPH_POLYSEGMENT_H
