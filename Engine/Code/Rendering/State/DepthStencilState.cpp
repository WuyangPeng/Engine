///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:17)

#include "Rendering/RenderingExport.h"

#include "DepthStencilState.h"
#include "Flags/DepthStencilStateComparison.h"
#include "Flags/DepthStencilStateWriteMask.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/OpenGLRenderer/State/OpenGLDepthStencilState.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, DepthStencilState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DepthStencilState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DepthStencilState);

Rendering::DepthStencilState::DepthStencilStateSharedPtr Rendering::DepthStencilState::Create(const std::string& name)
{
    return std::make_shared<DepthStencilState>(DepthStencilStateCreate::Init, name);
}

Rendering::DepthStencilState::DepthStencilState(DepthStencilStateCreate depthStencilStateCreate, const std::string& name)
    : ParentType{ name, GraphicsObjectType::DepthStencilState },
      depthEnable{ true },
      writeMask{ DepthStencilStateWriteMask::All },
      comparison{ DepthStencilStateComparison::LessEqual },
      stencilEnable{ false },
      stencilReadMask{ 0xFF },
      stencilWriteMask{ 0xFF },
      frontFace{},
      backFace{},
      reference{ 0 }
{
    System::UnusedFunction(depthStencilStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthStencilState)

Rendering::DepthStencilState::DepthStencilState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      depthEnable{ true },
      writeMask{ DepthStencilStateWriteMask::All },
      comparison{ DepthStencilStateComparison::LessEqual },
      stencilEnable{ false },
      stencilReadMask{ 0xFF },
      stencilWriteMask{ 0xFF },
      frontFace{},
      backFace{},
      reference{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DepthStencilState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += RENDERING_STREAM_SIZE(depthEnable);
    size += RENDERING_STREAM_SIZE(writeMask);
    size += RENDERING_STREAM_SIZE(comparison);
    size += RENDERING_STREAM_SIZE(stencilEnable);
    size += RENDERING_STREAM_SIZE(stencilReadMask);
    size += RENDERING_STREAM_SIZE(stencilWriteMask);
    size += RENDERING_STREAM_SIZE(frontFace);
    size += RENDERING_STREAM_SIZE(backFace);
    size += RENDERING_STREAM_SIZE(reference);

    return size;
}

int64_t Rendering::DepthStencilState::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::DepthStencilState::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(depthEnable);
    target.WriteEnum(writeMask);
    target.WriteEnum(comparison);
    target.Write(stencilEnable);
    target.Write(stencilReadMask);
    target.Write(stencilWriteMask);
    target.WriteAggregate(frontFace);
    target.WriteAggregate(backFace);
    target.Write(reference);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DepthStencilState::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::DepthStencilState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DepthStencilState::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(depthEnable);
    source.ReadEnum(writeMask);
    source.ReadEnum(comparison);
    source.Read(stencilEnable);
    source.Read(stencilReadMask);
    source.Read(stencilWriteMask);
    source.ReadAggregate(frontFace);
    source.ReadAggregate(backFace);
    source.Read(reference);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CheckDepthStencilState();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::DepthStencilState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

bool Rendering::DepthStencilState::IsDepthEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthEnable;
}

void Rendering::DepthStencilState::SetDepthEnable(bool aDepthEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthEnable = aDepthEnable;
}

Rendering::DepthStencilStateWriteMask Rendering::DepthStencilState::GetWriteMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return writeMask;
}

void Rendering::DepthStencilState::SetWriteMask(DepthStencilStateWriteMask depthStencilStateWriteMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    writeMask = depthStencilStateWriteMask;
}

Rendering::DepthStencilStateComparison Rendering::DepthStencilState::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return comparison;
}

void Rendering::DepthStencilState::SetComparison(DepthStencilStateComparison depthStencilStateComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    comparison = depthStencilStateComparison;
}

bool Rendering::DepthStencilState::IsStencilEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilEnable;
}

void Rendering::DepthStencilState::SetStencilEnable(bool aStencilEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilEnable = aStencilEnable;
}

int Rendering::DepthStencilState::GetStencilReadMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilReadMask;
}

void Rendering::DepthStencilState::SetStencilReadMask(int aStencilReadMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilReadMask = aStencilReadMask;
}

int Rendering::DepthStencilState::GetStencilWriteMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilWriteMask;
}

void Rendering::DepthStencilState::SetStencilWriteMask(int aStencilWriteMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilWriteMask = aStencilWriteMask;
}

Rendering::DepthStencilStateFace Rendering::DepthStencilState::GetFrontFace() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace;
}

Rendering::DepthStencilStateFace Rendering::DepthStencilState::GetBackFace() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return backFace;
}

void Rendering::DepthStencilState::SetFrontFaceFail(DepthStencilStateOperation fail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontFace.SetFail(fail);
}

void Rendering::DepthStencilState::SetFrontFaceDepthFail(DepthStencilStateOperation depthFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontFace.SetDepthFail(depthFail);
}

void Rendering::DepthStencilState::SetFrontFacePass(DepthStencilStateOperation pass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontFace.SetPass(pass);
}

void Rendering::DepthStencilState::SetFrontFaceComparison(DepthStencilStateComparison aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontFace.SetComparison(aComparison);
}

void Rendering::DepthStencilState::SetBackFaceFail(DepthStencilStateOperation fail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    backFace.SetFail(fail);
}

void Rendering::DepthStencilState::SetBackFaceDepthFail(DepthStencilStateOperation depthFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    backFace.SetDepthFail(depthFail);
}

void Rendering::DepthStencilState::SetBackFacePass(DepthStencilStateOperation pass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    backFace.SetPass(pass);
}

void Rendering::DepthStencilState::SetBackFaceComparison(DepthStencilStateComparison aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    backFace.SetComparison(aComparison);
}

int Rendering::DepthStencilState::GetReference() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reference;
}

void Rendering::DepthStencilState::SetReference(int aReference) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    reference = aReference;
}

void Rendering::DepthStencilState::CheckDepthStencilState()
{
    if (GetType() != GraphicsObjectType::DepthStencilState)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject类型错误。"s));
    }
}

Rendering::DepthStencilState::RendererObjectSharedPtr Rendering::DepthStencilState::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLDepthStencilState>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}