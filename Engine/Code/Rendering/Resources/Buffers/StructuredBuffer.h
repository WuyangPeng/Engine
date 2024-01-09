/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:49)

#ifndef RENDERING_RESOURCES_STRUCTURED_BUFFER_H
#define RENDERING_RESOURCES_STRUCTURED_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE StructuredBuffer : public Buffer
    {
    public:
        using ClassType = StructuredBuffer;
        using ParentType = Buffer;

        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;

    public:
        StructuredBuffer(const std::string& name, int numElements, int elementSize, bool createStorage = true);
        StructuredBuffer(const std::string& name, int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StructuredBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD StructuredBufferSharedPtr Clone() const;

        NODISCARD CounterType GetCounterType() const noexcept;

        /// �ڽ��������󶨵�����֮ǰ����������һ��������
        /// �⽫����CounterType�������÷�����ΪShaderOutput��
        void MakeAppendConsume() noexcept;
        void MakeCounter() noexcept;

        /// ���������м�������AppendConsume��Counter��ʱ��
        /// ��GPU֪���Ƿ�������ڲ�������
        /// ��true����������ζ��GPU���ü����������䵱ǰֵ��
        /// ���������ļ���������ΪNoneʱ���˺����������ԡ�
        void SetKeepInternalCount(bool aKeepInternalCount) noexcept;
        NODISCARD bool GetKeepInternalCount() const noexcept;

        // ����ɫ�������ڴ洢������Ϣ��
        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 2;
        }

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        CounterType counterType;
        bool keepInternalCount;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StructuredBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StructuredBuffer);
}

#endif  // RENDERING_RESOURCES_STRUCTURED_BUFFER_H
