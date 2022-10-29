///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/16 22:18)

#include "Rendering/RenderingExport.h"

#include "OpenGLResource.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/CopyType.h"

Rendering::OpenGLResource::OpenGLResource(const ResourceSharedPtr& resource, const std::string& name)
    : ParentType{ resource, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLResource)

Rendering::ConstResourceSharedPtr Rendering::OpenGLResource::GetResource() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Resource>(GetGraphicsObject());
}

bool Rendering::OpenGLResource::PreparedForCopy(BufferLocking access) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (GetGLHandle() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GL���󲻴��ڡ�"s));
    }

    const auto copyType = GetResource()->GetCopy();
    if (copyType == CopyType::CpuToStaging)  // CPU -> GPU
    {
        if (access == System::BufferLocking::WriteOnly)
        {
            return true;
        }
    }
    else if (copyType == CopyType::StagingToCpu)  // GPU -> CPU
    {
        if (access == System::BufferLocking::ReadOnly)
        {
            return true;
        }
    }
    else if (copyType == CopyType::Bidirectional)
    {
        if (access == System::BufferLocking::ReadWrite)
        {
            return true;
        }
        if (access == System::BufferLocking::WriteOnly)
        {
            return true;
        }
        if (access == System::BufferLocking::ReadOnly)
        {
            return true;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��Դ��copy���ʹ���"s));
}
