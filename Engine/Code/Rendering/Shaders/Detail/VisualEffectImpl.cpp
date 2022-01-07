// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:38)

#include "Rendering/RenderingExport.h"

#include "VisualEffectImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26440)

Rendering::VisualEffectImpl ::VisualEffectImpl()
    : m_Techniques{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualEffectImpl)

int Rendering::VisualEffectImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CORE_TOOLS_STREAM_SIZE(m_Techniques);
}

void Rendering::VisualEffectImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //	target.WriteSharedPtr(m_Techniques);
}

void Rendering::VisualEffectImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //	source.ReadSharedPtr(m_Techniques);
}

void Rendering::VisualEffectImpl ::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    if (!m_Techniques.empty())
    {
        //source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_Techniques.size()), &m_Techniques[0]);
    }
}

void Rendering::VisualEffectImpl ::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    if (!m_Techniques.empty())
    {
        //target.RegisterSharedPtr(boost::numeric_cast<int>(m_Techniques.size()), &m_Techniques[0]);
    }
}

CoreTools::ObjectSharedPtr Rendering::VisualEffectImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& pointer : m_Techniques)
    {
        auto found = pointer->GetObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return CoreTools::ObjectSharedPtr();
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualEffectImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects;

    for (auto& pointer : m_Techniques)
    {
        auto singleObjects = pointer->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualEffectImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& pointer : m_Techniques)
    {
        auto found = pointer->GetConstObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return CoreTools::ConstObjectSharedPtr();
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualEffectImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ConstObjectSharedPtr> objects;

    for (const auto& pointer : m_Techniques)
    {
        auto singleObjects = pointer->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

void Rendering::VisualEffectImpl ::InsertTechnique(const VisualTechniqueSharedPtr& technique)
{
    RENDERING_CLASS_IS_VALID_9;

    m_Techniques.push_back(technique);
}

int Rendering::VisualEffectImpl ::GetNumTechniques() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Techniques.size());
}

const Rendering::ConstVisualTechniqueSharedPtr Rendering::VisualEffectImpl ::GetTechnique(int techniqueIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex];
}

int Rendering::VisualEffectImpl ::GetNumPasses(int techniqueIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetNumPasses();
}

const Rendering::ConstVisualPassSharedPtr Rendering::VisualEffectImpl ::GetPass(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetPass(passIndex);
}

const Rendering::ConstVertexShaderSharedPtr Rendering::VisualEffectImpl ::GetVertexShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetVertexShader(passIndex);
}

const Rendering::ConstPixelShaderSharedPtr Rendering::VisualEffectImpl ::GetPixelShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetPixelShader(passIndex);
}

const Rendering::ConstAlphaStateSharedPtr Rendering::VisualEffectImpl ::GetAlphaState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetAlphaState(passIndex);
}

const Rendering::ConstCullStateSharedPtr Rendering::VisualEffectImpl ::GetCullState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetCullState(passIndex);
}

const Rendering::ConstDepthStateSharedPtr Rendering::VisualEffectImpl ::GetDepthState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetDepthState(passIndex);
}

const Rendering::ConstOffsetStateSharedPtr Rendering::VisualEffectImpl ::GetOffsetState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetOffsetState(passIndex);
}

const Rendering::ConstStencilStateSharedPtr Rendering::VisualEffectImpl ::GetStencilState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetStencilState(passIndex);
}

const Rendering::ConstWireStateSharedPtr Rendering::VisualEffectImpl ::GetWireState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

    return m_Techniques[techniqueIndex]->GetWireState(passIndex);
}

void Rendering::VisualEffectImpl ::SaveVisualTechnique(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numTechniques = GetNumTechniques();
    manager.Write(sizeof(int), &numTechniques);

    for (auto i = 0; i < numTechniques; ++i)
    {
        m_Techniques[i]->SaveVisualPass(manager);
    }
}

void Rendering::VisualEffectImpl ::LoadVisualTechnique(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numTechniques = 0;
    manager.Read(sizeof(int), &numTechniques);

    for (auto i = 0; i < numTechniques; ++i)
    {
        VisualTechniqueSharedPtr technique{ std::make_shared<VisualTechnique>() };

        technique->LoadVisualPass(manager);

        InsertTechnique(technique);
    }
}

#include STSTEM_WARNING_POP