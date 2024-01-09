/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:42)

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

Rendering::NodeImpl::NodeImpl() noexcept
    : spatialChild{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::NodeImpl::~NodeImpl() noexcept
{
    EXCEPTION_TRY
    {
        DetachAllChildren();
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

int Rendering::NodeImpl::AttachChild(const SpatialSharedPtr& child, const SpatialSharedPtr& self)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!child)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�㲻�ܸ���һ���սڵ㵽Node��\n"))
    }

    if (!child->GetParent()->IsNullObject())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ӽڵ��ѱ����ӵ���һNode��\n"))
    }

    child->SetParent(self);

    // �����ӽڵ㵽��һ�����ò��(����еĻ�)��
    const auto numChildren = GetNumChildren();

    if (const auto index = GetFirstNullIndex();
        0 <= index && index < numChildren)
    {
        spatialChild.at(index).object = child;
        return index;
    }
    else
    {
        // ���в�۶���ʹ�ã������ӽڵ㵽������档
        spatialChild.emplace_back(child);
        return numChildren;
    }
}

int Rendering::NodeImpl::GetFirstNullIndex() const noexcept
{
    auto index = 0;
    for (const auto& current : spatialChild)
    {
        if (!current.object)
        {
            return index;
        }
        ++index;
    }

    return -1;
}

int Rendering::NodeImpl::DetachChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_9;

    if (child != nullptr && !child->IsNullObject())
    {
        auto index = 0;
        for (auto& current : spatialChild)
        {
            if (current.object == child)
            {
                current.object->SetParent(nullptr);
                current.object.reset();

                return index;
            }
            ++index;
        }
    }

    return -1;
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::DetachChildAt(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    if (0 <= index && index < GetNumChildren())
    {
        auto child = spatialChild.at(index).object;
        if (child != nullptr)
        {
            child->SetParent(nullptr);
            spatialChild.at(index).object.reset();
        }

        return child;
    }

    return Spatial::GetNullObject();
}

void Rendering::NodeImpl::DetachAllChildren()
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& child : spatialChild)
    {
        if (child.object != nullptr)
        {
            child.object->SetParent(nullptr);
            child.object.reset();
        }
    }
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::SetChild(int index, const SpatialSharedPtr& child, const SpatialSharedPtr& self)
{
    RENDERING_CLASS_IS_VALID_9;

    if (child != nullptr && !child->GetParent()->IsNullObject())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ӽڵ��ѱ����ӵ���һNode��\n"))
    }

    if (0 <= index && index < GetNumChildren())
    {
        // �Ӳ�����Ƴ���ǰ���ӽڵ㡣
        auto previousChild = spatialChild.at(index).object;
        if (previousChild != nullptr && !previousChild->IsNullObject())
        {
            previousChild->SetParent(nullptr);
        }

        // ����һ���µ��ӽڵ㵽��ۡ�
        if (child != nullptr)
        {
            child->SetParent(self);
        }

        spatialChild.at(index).object = child;

        return previousChild == nullptr ? Spatial::GetNullObject() : previousChild;
    }

    // ���������˷�Χ�������ӽڵ㵽���顣
    if (child)
    {
        child->SetParent(self);
    }

    spatialChild.emplace_back(child);

    return Spatial::GetNullObject();
}

Rendering::SpatialSharedPtr Rendering::NodeImpl::GetChild(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return std::const_pointer_cast<Spatial>(GetConstChild(index));
}

Rendering::ConstSpatialSharedPtr Rendering::NodeImpl::GetConstChild(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index < GetNumChildren())
    {
        if (const auto result = spatialChild.at(index).object;
            result != nullptr)
        {
            return result;
        }
    }

    return Spatial::GetNullObject();
}

bool Rendering::NodeImpl::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = true;

    for (const auto& element : spatialChild)
    {
        if (const auto child = element.object;
            child != nullptr)
        {
            if (!child->Update(applicationTime, false))
            {
                result = false;
            }
        }
    }

    return result;
}

Mathematics::BoundingSphereF Rendering::NodeImpl::GetWorldBound() const
{
    RENDERING_CLASS_IS_VALID_9;

    // ��һ����Ч�ı߽翪ʼ��
    BoundingSphere bound{ Mathematics::APointF::GetOrigin(), 0.0f };

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr)
        {
            // GrowToContain������Ч���ӱ߽硣
            // �����������Ч�ĺ��ӱ߽�����Ч,�ӱ߽�Ḵ�Ƶ�����߽硣
            // �������߽���ӱ߽綼����Ч��,��С�İ��������߽�ı߽�ḳֵ������߽硣
            bound.GrowToContain(child->GetWorldBound());
        }
    }

    return bound;
}

void Rendering::NodeImpl::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr)
        {
            child->OnGetVisibleSet(culler, camera, noCull);
        }
    }
}

CoreTools::ObjectSharedPtr Rendering::NodeImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return Object::GetNullObject();
}

Rendering::NodeImpl::ObjectSharedPtrContainer Rendering::NodeImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer result{};

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr && child->GetName() == name)
        {
            result.emplace_back(child);
        }
    }

    return result;
}

CoreTools::ConstObjectSharedPtr Rendering::NodeImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr && child->GetName() == name)
        {
            return child;
        }
    }

    return Object::GetNullObject();
}

Rendering::NodeImpl::ConstObjectSharedPtrContainer Rendering::NodeImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    ConstObjectSharedPtrContainer result{};

    for (const auto& element : spatialChild)
    {
        if (auto child = element.object;
            child != nullptr && child->GetName() == name)
        {
            result.emplace_back(child);
        }
    }

    return result;
}

void Rendering::NodeImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociatedContainer(spatialChild);
}

void Rendering::NodeImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLinkContainer(spatialChild);
}

void Rendering::NodeImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    spatialChild.clear();
}

Rendering::PickRecordContainer Rendering::NodeImpl::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax, int numThreads, float maxDistance) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto container = PickRecordContainer::Create();

    if (const auto worldBound = GetWorldBound();
        worldBound.TestIntersection(origin, direction, tMin, tMax))
    {
        for (const auto& element : spatialChild)
        {
            if (const auto child = element.object;
                child != nullptr)
            {
                const auto childContainer = child->ExecuteRecursive(origin, direction, tMin, tMax, numThreads, maxDistance);

                container.InsertPickRecord(childContainer);
            }
        }
    }

    return container;
}

void Rendering::NodeImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.RegisterContainer(spatialChild);
}

void Rendering::NodeImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociatedContainerWithNumber(spatialChild);
}

int Rendering::NodeImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetStreamSize(spatialChild);
}
