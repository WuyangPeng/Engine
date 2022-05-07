///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 18:24)

#include "Rendering/RenderingExport.h"

#include "VisualTechniqueImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;
using std::vector;

Rendering::VisualTechniqueImpl::VisualTechniqueImpl() noexcept
    : passes{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualTechniqueImpl)

int Rendering::VisualTechniqueImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CORE_TOOLS_STREAM_SIZE(passes);
}

void Rendering::VisualTechniqueImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociatedContainerWithNumber(passes);
}

void Rendering::VisualTechniqueImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociatedContainer(passes);
}

void Rendering::VisualTechniqueImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!passes.empty())
    {
        source.ResolveLinkContainer(passes);
    }
}

void Rendering::VisualTechniqueImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!passes.empty())
    {
        target.RegisterContainer(passes);
    }
}

void Rendering::VisualTechniqueImpl::InsertPass(const VisualPassSharedPtr& pass)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(pass != nullptr, "输入的pass必须是有效的。");

    passes.emplace_back(pass);
}

int Rendering::VisualTechniqueImpl::GetNumPasses() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(passes.size());
}

Rendering::ConstVisualPassSharedPtr Rendering::VisualTechniqueImpl::GetPass(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object;
}

Rendering::ConstVertexShaderSharedPtr Rendering::VisualTechniqueImpl::GetVertexShader(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetVertexShader();
}

Rendering::ConstPixelShaderSharedPtr Rendering::VisualTechniqueImpl::GetPixelShader(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetPixelShader();
}

Rendering::ConstAlphaStateSharedPtr Rendering::VisualTechniqueImpl::GetAlphaState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetAlphaState();
}

Rendering::ConstCullStateSharedPtr Rendering::VisualTechniqueImpl::GetCullState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetCullState();
}

Rendering::ConstDepthStateSharedPtr Rendering::VisualTechniqueImpl::GetDepthState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetDepthState();
}

Rendering::ConstOffsetStateSharedPtr Rendering::VisualTechniqueImpl::GetOffsetState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetOffsetState();
}

Rendering::ConstStencilStateSharedPtr Rendering::VisualTechniqueImpl::GetStencilState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetStencilState();
}

Rendering::ConstWireStateSharedPtr Rendering::VisualTechniqueImpl::GetWireState(int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(), "索引错误！");

    return passes.at(passIndex).object->GetWireState();
}

CoreTools::ObjectSharedPtr Rendering::VisualTechniqueImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& pointer : passes)
    {
        auto found = pointer.object->GetObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualTechniqueImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects{};

    for (auto& pointer : passes)
    {
        auto singleObjects = pointer.object->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualTechniqueImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& pointer : passes)
    {
        auto found = pointer.object->GetConstObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualTechniqueImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ConstObjectSharedPtr> objects{};

    for (const auto& pointer : passes)
    {
        auto singleObjects = pointer.object->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

void Rendering::VisualTechniqueImpl::SaveVisualPass(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numPasses = GetNumPasses();
    manager.Write(sizeof(int32_t), &numPasses);
    for (auto i = 0; i < numPasses; ++i)
    {
        passes.at(i).object->SaveShader(manager);
        passes.at(i).object->SaveState(manager);
    }
}

void Rendering::VisualTechniqueImpl::LoadVisualPass(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numPasses = 0;
    manager.Read(sizeof(int32_t), &numPasses);

    for (auto i = 0; i < numPasses; ++i)
    {
        auto pass = std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable);

        pass->LoadShader(manager);
        pass->LoadState(manager);

        InsertPass(std::move(pass));
    }
}
