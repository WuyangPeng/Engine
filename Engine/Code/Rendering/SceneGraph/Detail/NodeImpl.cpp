// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 16:15)

#include "Rendering/RenderingExport.h"

#include "NodeImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Node.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::NodeImpl ::NodeImpl(Node* realThis)
    : m_Child{}, m_RealThis{ realThis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::NodeImpl ::~NodeImpl()
{
    EXCEPTION_TRY
    {
        for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
        {
            if (*iter != nullptr)
            {
                (*iter)->SetObject(nullptr);
                iter->reset();
            }
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, NodeImpl)

int Rendering::NodeImpl ::GetNumChildren() const
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::numeric_cast<int>(m_Child.size());
}

int Rendering::NodeImpl ::AttachChild(SpatialSharedPtr child)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!child)
    {
        RENDERING_ASSERTION_1(false, "�㲻�ܸ���һ���սڵ㵽NodeImpl��\n");
        return -1;
    }

    if (child->GetParent() != nullptr)
    {
        RENDERING_ASSERTION_1(false, "�ӽڵ��ѱ����ӵ���һNodeImpl��\n");
        return -1;
    }

    child->SetParent(m_RealThis);

    // �����ӽڵ㵽��һ�����ò��(����еĻ�)��
    const auto index = GetFirstNullIndex();
    if (0 <= index && index < boost::numeric_cast<int>(m_Child.size()))
    {
        m_Child[index] = child;
        return index;
    }
    else
    {
        // ���в�۶���ʹ�ã������ӽڵ㵽������档
        const auto numChildren = boost::numeric_cast<int>(m_Child.size());
        m_Child.push_back(child);
        return numChildren;
    }
}

// private
int Rendering::NodeImpl ::GetFirstNullIndex() const noexcept
{
    for (auto index = 0u; index < m_Child.size(); ++index)
    {
        if (!m_Child[index])
        {
            return index;
        }
    }

    return -1;
}

int Rendering::NodeImpl ::DetachChild(SpatialSharedPtr child) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (child)
    {
        for (auto index = 0u; index < m_Child.size(); ++index)
        {
            if (m_Child[index] == child)
            {
                m_Child[index]->SetParent(nullptr);
                m_Child[index].reset();

                return index;
            }
        }
    }

    return -1;
}

Rendering::SpatialSharedPtr Rendering::NodeImpl ::DetachChildAt(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (0 <= index && index < boost::numeric_cast<int>(m_Child.size()))
    {
        auto child = m_Child[index];
        if (child)
        {
            child->SetParent(nullptr);
            m_Child[index].reset();
        }

        return child;
    }
    return SpatialSharedPtr{};
}

Rendering::SpatialSharedPtr Rendering::NodeImpl ::SetChild(int index, const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_9;

    if (child != nullptr)
    {
        RENDERING_ASSERTION_1(!child->GetParent(), "�ӽڵ��ѱ����ӵ���һNodeImpl��\n");
    }

    const auto numChildren = boost::numeric_cast<int>(m_Child.size());
    if (0 <= index && index < numChildren)
    {
        // �Ӳ�����Ƴ���ǰ���ӽڵ㡣
        auto previousChild = m_Child[index];
        if (previousChild != nullptr)
        {
            previousChild->SetParent(nullptr);
        }

        // ����һ���µ��ӽڵ㵽��ۡ�
        if (child != nullptr)
        {
            child->SetParent(m_RealThis);
        }

        m_Child[index] = child;

        return previousChild;
    }

    // ���������˷�Χ�������ӽڵ㵽���顣
    if (child)
    {
        child->SetParent(m_RealThis);
    }

    m_Child.push_back(child);

    return SpatialSharedPtr{};
}

Rendering::SpatialSharedPtr Rendering::NodeImpl ::GetChild(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (0 <= index && index < boost::numeric_cast<int>(m_Child.size()))
    {
        return m_Child[index];
    }

    return SpatialSharedPtr{};
}

Rendering::ConstSpatialSharedPtr Rendering::NodeImpl ::GetConstChild(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < boost::numeric_cast<int>(m_Child.size()))
    {
        return m_Child[index];
    }

    return ConstSpatialSharedPtr{};
}

bool Rendering::NodeImpl ::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = true;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;

        if (child)
        {
            if (!child->Update(applicationTime, false))
            {
                result = false;
            }
        }
    }

    return result;
}

const Rendering::FloatBound Rendering::NodeImpl ::GetWorldBound()
{
    RENDERING_CLASS_IS_VALID_9;

    // ��һ����Ч�ı߽翪ʼ��
    FloatBound bound{ Mathematics::APointF::GetOrigin(), 0.0f };

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;

        if (child != nullptr)
        {
            // GrowToContain������Ч���ӱ߽硣
            // �����������Ч�ĺ��ӱ߽�����Ч,�ӱ߽�Ḵ�Ƶ�����߽硣
            // �������߽���ӱ߽綼����Ч��,��С�İ��������߽�ı߽�ḳֵ������߽硣
            bound.GrowToContain(child->GetWorldBound());
        }
    }

    return bound;
}

void Rendering::NodeImpl ::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;

        if (child != nullptr)
        {
            child->OnGetVisibleSet(culler, noCull);
        }
    }
}

// ����֧�֡�

CoreTools::ObjectSharedPtr Rendering::NodeImpl ::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;

        if (child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return CoreTools::ObjectSharedPtr();
}

vector<CoreTools::ObjectSharedPtr> Rendering::NodeImpl ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ObjectSharedPtr> objects;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;

        if (child != nullptr && child->GetName() == name)
        {
            objects.push_back(child);
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::NodeImpl ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;  //->PolymorphicCastConstObjectSharedPtr<ConstSpatialSharedPtr>();

        if (child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return CoreTools::ConstObjectSharedPtr{};
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::NodeImpl ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    vector<CoreTools::ConstObjectSharedPtr> objects;

    for (auto iter = m_Child.begin(), end = m_Child.end(); iter != end; ++iter)
    {
        auto child = *iter;  //->PolymorphicCastConstObjectSharedPtr<ConstSpatialSharedPtr>();

        if (child != nullptr && child->GetName() == name)
        {
            objects.push_back(child);
        }
    }

    return objects;
}

// ��֧��

void Rendering::NodeImpl ::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    int numChildren{ 0 };
    source.Read(numChildren);

    m_Child.resize(numChildren);

    if (!m_Child.empty())
    {
        //  source.ReadSharedPtr(boost::numeric_cast<int>(m_Child.size()),&m_Child[0]);
    }
}

void Rendering::NodeImpl ::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    const auto numChildren = boost::numeric_cast<int>(m_Child.size());

    for (auto i = 0; i < numChildren; ++i)
    {
        //  if (m_Child[i].GetAddress() != 0)
        {
            //     source.ResolveObjectSharedPtrLink(m_Child[i]);
            //       SetChild(i, m_Child[i]);
        }
    }
}

void Rendering::NodeImpl ::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    const auto numChildren = boost::numeric_cast<int>(m_Child.size());

    for (auto i = 0; i < numChildren; ++i)
    {
        if (m_Child[i])
        {
            // target.RegisterSharedPtr(m_Child[i]);
        }
    }
}

void Rendering::NodeImpl ::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numChildren = boost::numeric_cast<int>(m_Child.size());
    target.Write(numChildren);

    if (!m_Child.empty())
    {
        //	target.WriteSharedPtrWithoutNumber(boost::numeric_cast<int>(m_Child.size()), &m_Child[0]);
    }
}

int Rendering::NodeImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto numChildren = boost::numeric_cast<int>(m_Child.size());

    auto size = CORE_TOOLS_STREAM_SIZE(numChildren);

    if (0 < numChildren)
    {
        size += numChildren * CORE_TOOLS_STREAM_SIZE(m_Child[0]);
    }

    return size;
}

#include STSTEM_WARNING_POP