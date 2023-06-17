///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "NodeImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Node.h"

Rendering::NodeImpl::NodeImpl(Node* realThis) noexcept
    : spatialChild{}, realThis{ realThis }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::NodeImpl::~NodeImpl() noexcept
{
    EXCEPTION_TRY
    {
        for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
        {
            if (iter->object != nullptr)
            {
                iter->object->SetObject(nullptr);
                iter->object.reset();
            }
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, NodeImpl)

int Rendering::NodeImpl::GetNumChildren() const
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::numeric_cast<int>(spatialChild.size());
}

int Rendering::NodeImpl::AttachChild(const SpatialSharedPtr& child)
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

    child->SetParent(realThis);

    // �����ӽڵ㵽��һ�����ò��(����еĻ�)��
    const auto index = GetFirstNullIndex();
    if (0 <= index && index < boost::numeric_cast<int>(spatialChild.size()))
    {
        spatialChild.at(index).object = child;
        return index;
    }
    else
    {
        // ���в�۶���ʹ�ã������ӽڵ㵽������档
        const auto numChildren = boost::numeric_cast<int>(spatialChild.size());
        spatialChild.emplace_back(child);
        return numChildren;
    }
}

// private
int Rendering::NodeImpl::GetFirstNullIndex() const
{
    for (auto index = 0u; index < spatialChild.size(); ++index)
    {
        if (!spatialChild.at(index).object)
        {
            return index;
        }
    }

    return -1;
}

int Rendering::NodeImpl::DetachChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_9;

    if (child != nullptr)
    {
        for (auto index = 0u; index < spatialChild.size(); ++index)
        {
            if (spatialChild.at(index).object == child)
            {
                spatialChild.at(index).object->SetParent(nullptr);
                spatialChild.at(index).object.reset();

                return index;
            }
        }
    }

    return -1;
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::DetachChildAt(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (0 <= index && index < boost::numeric_cast<int>(spatialChild.size()))
    {
        auto child = spatialChild.at(index).object;
        if (child)
        {
            child->SetParent(nullptr);
            spatialChild.at(index).object.reset();
        }

        return child;
    }

    return nullptr;
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::SetChild(int index, const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_9;

    if (child != nullptr)
    {
        RENDERING_ASSERTION_1(!child->GetParent(), "�ӽڵ��ѱ����ӵ���һNodeImpl��\n");
    }

    const auto numChildren = boost::numeric_cast<int>(spatialChild.size());
    if (0 <= index && index < numChildren)
    {
        // �Ӳ�����Ƴ���ǰ���ӽڵ㡣
        auto previousChild = spatialChild.at(index).object;
        if (previousChild != nullptr)
        {
            previousChild->SetParent(nullptr);
        }

        // ����һ���µ��ӽڵ㵽��ۡ�
        if (child != nullptr)
        {
            child->SetParent(realThis);
        }

        spatialChild.at(index).object = child;

        return previousChild;
    }

    // ���������˷�Χ�������ӽڵ㵽���顣
    if (child)
    {
        child->SetParent(realThis);
    }

    spatialChild.emplace_back(child);

    return nullptr;
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::GetChild(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (0 <= index && index < boost::numeric_cast<int>(spatialChild.size()))
    {
        return spatialChild.at(index).object;
    }

    return nullptr;
}

Rendering::ConstSpatialSharedPtr Rendering::NodeImpl::GetConstChild(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < boost::numeric_cast<int>(spatialChild.size()))
    {
        return spatialChild.at(index).object;
    }

    return nullptr;
}

bool Rendering::NodeImpl::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = true;

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

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

Rendering::BoundF Rendering::NodeImpl::GetWorldBound()
{
    RENDERING_CLASS_IS_VALID_9;

    // ��һ����Ч�ı߽翪ʼ��
    BoundF bound{ Mathematics::APointF::GetOrigin(), 0.0f };

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

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

void Rendering::NodeImpl::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

        if (child != nullptr)
        {
            child->OnGetVisibleSet(culler, noCull);
        }
    }
}

// ����֧�֡�

CoreTools::ObjectSharedPtr Rendering::NodeImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

        if (child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::NodeImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    std::vector<CoreTools::ObjectSharedPtr> objects{};

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

        if (child != nullptr && child->GetName() == name)
        {
            objects.emplace_back(child);
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::NodeImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

        if (child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::NodeImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    std::vector<CoreTools::ConstObjectSharedPtr> objects{};

    for (auto iter = spatialChild.begin(); iter != spatialChild.end(); ++iter)
    {
        auto child = iter->object;

        if (child != nullptr && child->GetName() == name)
        {
            objects.emplace_back(child);
        }
    }

    return objects;
}

// ��֧��

void Rendering::NodeImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociatedContainer(spatialChild);
}

void Rendering::NodeImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLinkContainer(spatialChild);
}

void Rendering::NodeImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    spatialChild.clear();
}

void Rendering::NodeImpl::ChangeRealThis(Node* aRealThis) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    realThis = aRealThis;
}

void Rendering::NodeImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numChildren = boost::numeric_cast<int>(spatialChild.size());

    for (auto i = 0; i < numChildren; ++i)
    {
        if (spatialChild.at(i).object)
        {
            target.Register(spatialChild.at(i));
        }
    }
}

void Rendering::NodeImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociatedContainerWithNumber(spatialChild);
}

int Rendering::NodeImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto numChildren = boost::numeric_cast<int32_t>(spatialChild.size());

    auto size = CoreTools::GetStreamSize(numChildren);

    if (0 < numChildren)
    {
        size += numChildren * CoreTools::GetStreamSize(spatialChild.at(0));
    }

    return size;
}
