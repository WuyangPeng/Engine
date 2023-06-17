///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:18)

#include "Rendering/RenderingExport.h"

#include "SaveVisual.h"
#include "Visual.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

using CoreTools::WriteFileManager;

void Rendering::SaveVisual::SaveToFile(const Visual& visual, const System::String& name)
{
    RENDERING_ASSERTION_0(visual.GetConstVertexFormat() != nullptr, "VertexFormat�ǿ�ָ�룡");
    RENDERING_ASSERTION_0(visual.GetConstVertexBuffer() != nullptr, "VertexBuffer�ǿ�ָ�룡");

    WriteFileManager manager{ name };

    const auto type = visual.GetPrimitiveType();
    manager.Write(sizeof(VisualPrimitiveType), &type);
}
