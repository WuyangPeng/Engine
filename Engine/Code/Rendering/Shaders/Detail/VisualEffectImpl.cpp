///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.8.0.6 (2022/04/12 16:13)

#include "Rendering/RenderingExport.h"

#include "VisualEffectImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::string;
using std::vector;

Rendering::VisualEffectImpl::VisualEffectImpl() noexcept
    : techniques{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualEffectImpl)

int Rendering::VisualEffectImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CORE_TOOLS_STREAM_SIZE(techniques);
}

void Rendering::VisualEffectImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociatedContainerWithNumber(techniques);
}

void Rendering::VisualEffectImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociatedContainer(techniques);
}

void Rendering::VisualEffectImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLinkContainer(techniques);
}

void Rendering::VisualEffectImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.RegisterContainer(techniques);
}

CoreTools::ObjectSharedPtr Rendering::VisualEffectImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& pointer : techniques)
    {
        auto found = pointer.object->GetObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualEffectImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects{};

    for (auto& pointer : techniques)
    {
        auto singleObjects = pointer.object->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualEffectImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& pointer : techniques)
    {
        auto found = pointer.object->GetConstObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualEffectImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ConstObjectSharedPtr> objects{};

    for (const auto& pointer : techniques)
    {
        auto singleObjects = pointer.object->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

void Rendering::VisualEffectImpl::InsertTechnique(const VisualTechniqueSharedPtr& technique)
{
    RENDERING_CLASS_IS_VALID_9;

    techniques.emplace_back(technique);
}

int Rendering::VisualEffectImpl::GetNumTechniques() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(techniques.size());
}

Rendering::ConstVisualTechniqueSharedPtr Rendering::VisualEffectImpl::GetTechnique(int techniqueIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object;
}

int Rendering::VisualEffectImpl::GetNumPasses(int techniqueIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetNumPasses();
}

Rendering::ConstVisualPassSharedPtr Rendering::VisualEffectImpl::GetPass(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetPass(passIndex);
}

Rendering::ConstVertexShaderSharedPtr Rendering::VisualEffectImpl::GetVertexShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetVertexShader(passIndex);
}

Rendering::ConstPixelShaderSharedPtr Rendering::VisualEffectImpl::GetPixelShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetPixelShader(passIndex);
}

Rendering::ConstAlphaStateSharedPtr Rendering::VisualEffectImpl::GetAlphaState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetAlphaState(passIndex);
}

Rendering::ConstCullStateSharedPtr Rendering::VisualEffectImpl::GetCullState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetCullState(passIndex);
}

Rendering::ConstDepthStateSharedPtr Rendering::VisualEffectImpl::GetDepthState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetDepthState(passIndex);
}

Rendering::ConstOffsetStateSharedPtr Rendering::VisualEffectImpl::GetOffsetState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetOffsetState(passIndex);
}

Rendering::ConstStencilStateSharedPtr Rendering::VisualEffectImpl::GetStencilState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetStencilState(passIndex);
}

Rendering::ConstWireStateSharedPtr Rendering::VisualEffectImpl::GetWireState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "Ë÷Òý´íÎó£¡");

    return techniques.at(techniqueIndex).object->GetWireState(passIndex);
}

void Rendering::VisualEffectImpl::SaveVisualTechnique(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numTechniques = GetNumTechniques();
    manager.Write(sizeof(int32_t), &numTechniques);

    for (auto i = 0; i < numTechniques; ++i)
    {
        techniques.at(i).object->SaveVisualPass(manager);
    }
}

void Rendering::VisualEffectImpl::LoadVisualTechnique(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numTechniques = 0;
    manager.Read(sizeof(int32_t), &numTechniques);

    for (auto i = 0; i < numTechniques; ++i)
    {
        auto technique = std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable);

        technique->LoadVisualPass(manager);

        InsertTechnique(std::move(technique));
    }
}
