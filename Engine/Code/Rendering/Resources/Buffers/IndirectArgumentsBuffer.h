///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/10 10:27)

#ifndef RENDERING_RENDERERS_INDIRECT_ARGUMENTS_BUFFER_H
#define RENDERING_RENDERERS_INDIRECT_ARGUMENTS_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IndirectArgumentsBuffer : public Buffer
    {
    public:
        using ClassType = IndirectArgumentsBuffer;
        using ParentType = Buffer; 

    public:
        explicit IndirectArgumentsBuffer(int numElements);
        IndirectArgumentsBuffer(int numElements, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndirectArgumentsBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };
}

#endif  // RENDERING_RENDERERS_INDIRECT_ARGUMENTS_BUFFER_H
