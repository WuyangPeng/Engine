///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 11:54)

#include "Rendering/RenderingExport.h"

#include "DrawTarget.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLDrawTarget.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/Detail/Textures/DrawTargetImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DrawTarget)

CORE_TOOLS_RTTI_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DrawTarget);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, DrawTarget);

Rendering::DrawTarget::DrawTarget(int numRenderTargets,
                                  DataFormatType renderTargetFormat,
                                  int width,
                                  int height,
                                  bool hasRenderTargetMipmaps,
                                  DataFormatType depthStencilFormat)
    : ParentType{ "DrawTarget" },
      impl{ numRenderTargets, renderTargetFormat, width, height, hasRenderTargetMipmaps, depthStencilFormat }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DrawTarget)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetNumTargets, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetRenderTargetFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, HasRenderTargetMipmaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DrawTarget, HasDepthStencil, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DrawTarget, GetDepthStencilFormat, Rendering::DataFormatType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DrawTarget, GetRenderTargetTexture, int, Rendering::TextureRenderTargetSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetDepthStencilTexture, Rendering::TextureDepthStencilSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DrawTarget, GetRenderTargetTexture, int, Rendering::ConstTextureRenderTargetSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, GetDepthStencilTexture, Rendering::ConstTextureDepthStencilSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, AutogenerateRTMipmaps, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DrawTarget, WantAutogenerateRTMipmaps, bool)

Rendering::DrawTarget::DrawTarget(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DrawTarget::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::DrawTarget::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::DrawTarget::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DrawTarget::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::DrawTarget::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DrawTarget::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::DrawTarget::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::RendererDrawTargetSharedPtr Rendering::DrawTarget::CreateRendererDrawTarget(RendererTypes rendererTypes, const GraphicsObjectContainer& renderTargetTextures, GraphicsObject& depthStencilTexture)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            OpenGLDrawTarget::OpenGLTextureRenderTargetContainer container{};
            for (const auto& renderTargetTexture : renderTargetTextures)
            {
                container.emplace_back(boost::polymorphic_pointer_cast<OpenGLTextureRenderTarget>(renderTargetTexture->CreateRendererObject(rendererTypes)));
            }

            auto depthStencil = boost::polymorphic_pointer_cast<OpenGLTextureDepthStencil>(depthStencilTexture.CreateRendererObject(rendererTypes));

            return std::make_shared<OpenGLDrawTarget>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), container, depthStencil);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s));
        }
    }
}
