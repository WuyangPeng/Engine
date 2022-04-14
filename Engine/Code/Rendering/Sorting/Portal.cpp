// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 10:43)

#include "Rendering/RenderingExport.h"

#include "ConvexRegion.h"
#include "Portal.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26494)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26429)
CORE_TOOLS_RTTI_DEFINE(Rendering, Portal);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Portal);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Portal);

Rendering::Portal::Portal(int numVertices, Mathematics::APointF* modelVertices, const Mathematics::PlaneF& modelPlane, ConvexRegion* adjacentRegion, bool open)
    : ParentType("Portal"), AdjacentRegion(adjacentRegion), Open(open), mNumVertices(numVertices),
      mModelVertices(modelVertices), mModelPlane(modelPlane), mWorldPlane(modelPlane)
{
    mWorldVertices = nullptr;  //NEW1<Mathematics::APointF>(mNumVertices);
}

Rendering::Portal::~Portal(){
    EXCEPTION_TRY{
        //         DELETE1(mModelVertices);
        // DELETE1(mWorldVertices);
    } EXCEPTION_ALL_CATCH(Rendering)
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Portal::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

void Rendering::Portal::UpdateWorldData(const TransformF& worldTransform) noexcept
{
    for (int i = 0; i < mNumVertices; ++i)
    {
        mWorldVertices[i] = worldTransform * mModelVertices[i];
    }
    // œ»Õ®π˝±‡“Î
    // mWorldPlane = mModelPlane*worldTransform.GetInverseMatrix();
    // mWorldPlane.Normalize();
}

bool Rendering::Portal::ReducedFrustum(const Culler& culler, float reducedFrustum[6])
{
    // The portal polygon is transformed into the camera coordinate system
    // and projected onto the near plane.  An axis-aligned bounding rectangle
    // is computed for the projected points and clipped against the left,
    // right, bottom, and top frustum planes.  The result is itself an
    // axis-aligned bounding rectangle that is used to define a "reduced
    // frustum" to be used for drawing what is visible through the portal
    // polygon.
    //
    // The algorithm must handle the situation when portal polygon vertices
    // are behind the observer.  Imagine standing in a room with a doorway
    // immediately to your left.  Part of the doorway frame is in front of
    // you (and visible) and part of it is behind you (and not visible).
    // A portal point is represented by P = E + d*D + u*U + r*R, where E is
    // the world location for the eye point, D is the camera's world direction
    // vector, U is the camera's world up vector, and R is the camera's world
    // right vector.  The camera coordinates for the portal point are (d,u,r).
    // If d > 0, P is in front of the eye point and has a projection onto the
    // near plane d = n.  If d < 0, P is behind the eye point and does not
    // have a projection onto the near plane.  If d = 0, P projects to
    // "infinity" on the near plane, a problematic case to deal with.
    //
    // To avoid dealing with d = 0, choose a small value e such that
    // 0 < e < n.  The portal polygon is clipped against the plane d = e,
    // keeping only that portion whose points satisfy d >= e.  The clipped
    // polygon always has a projection onto the near plane.  The axis-aligned
    // bounding box for this projection is computed; clipped against the
    // left, right, bottom, and top of the frustum; and the result used to
    // define the reduced frustum.  All this is designed for an inexact
    // culling of the objects in the adjacent room, so it is useful to avoid
    // preserving the topology of the portal polygon as it is clipped.
    // Instead, the portal polygon vertices with d > e are projected and
    // the intersection points of portal polygon edges with d = e are
    // computed and projected.  The axis-aligned bounding box is computed for
    // the projections, a process that does not require knowing the polygon
    // topology.  The algorithm is essentially the one used for clipping a
    // convex polygon against the view frustum in the software renderer.  The
    // polygon vertices are traversed in-order and the signs of the d values
    // are updated accordingly.  This avoids computing d-signs twice per
    // vertex.

    const ConstCameraSharedPtr camera = culler.GetCamera();
    const float* frustum = culler.GetFrustum();
    float rmin = +Mathematics::MathF::maxReal;  // left
    float rmax = -Mathematics::MathF::maxReal;  // right
    float umin = +Mathematics::MathF::maxReal;  // bottom
    float umax = -Mathematics::MathF::maxReal;  // top

    Mathematics::AVectorF diff{};
    Mathematics::APointF vertexCam;
    int i = 0;

    if (camera->IsPerspective())
    {
        constexpr float epsilon = 1e-6f, invEpsilon = 1e+6f;
        int firstSign = 0, lastSign = 0;  // in {-1,0,1}
        bool signChange = false;
        Mathematics::APointF firstVertex = Mathematics::APointF::GetOrigin();
        Mathematics::APointF lastVertex = Mathematics::APointF::GetOrigin();
        float NdD = 0.0f, UdD = 0.0f, RdD = 0.0f, t = 0.0f;

        for (i = 0; i < mNumVertices; i++)
        {
            diff = mWorldVertices[i] - camera->GetPosition();
            vertexCam[0] = Dot(diff, camera->GetDirectionVector());
            vertexCam[1] = Dot(diff, camera->GetUpVector());
            vertexCam[2] = Dot(diff, camera->GetRightVector());
            vertexCam[3] = 1.0f;

            if (vertexCam[0] > epsilon)
            {
                if (firstSign == 0)
                {
                    firstSign = 1;
                    firstVertex = vertexCam;
                }

                NdD = frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] / vertexCam[0];
                UdD = vertexCam[1] * NdD;
                RdD = vertexCam[2] * NdD;

                if (UdD < umin)
                {
                    umin = UdD;
                }
                if (UdD > umax)
                {
                    umax = UdD;
                }

                if (RdD < rmin)
                {
                    rmin = RdD;
                }
                if (RdD > rmax)
                {
                    rmax = RdD;
                }

                if (lastSign < 0)
                {
                    signChange = true;
                }

                lastSign = 1;
            }
            else
            {
                if (firstSign == 0)
                {
                    firstSign = -1;
                    firstVertex = vertexCam;
                }

                if (lastSign > 0)
                {
                    signChange = true;
                }

                lastSign = -1;
            }

            if (signChange)
            {
                diff = vertexCam - lastVertex;
                t = (epsilon - lastVertex[0]) / diff[0];
                NdD = frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] * invEpsilon;
                UdD = (lastVertex[1] + t * diff[1]) * NdD;
                RdD = (lastVertex[2] + t * diff[2]) * NdD;

                if (UdD < umin)
                {
                    umin = UdD;
                }
                if (UdD > umax)
                {
                    umax = UdD;
                }

                if (RdD < rmin)
                {
                    rmin = RdD;
                }
                if (RdD > rmax)
                {
                    rmax = RdD;
                }

                signChange = false;
            }

            lastVertex = vertexCam;
        }

        if (firstSign * lastSign < 0)
        {
            // Process the last polygon edge.
            diff = firstVertex - lastVertex;
            t = (epsilon - lastVertex[0]) / diff[0];
            UdD = (lastVertex[1] + t * diff[1]) * invEpsilon;
            RdD = (lastVertex[2] + t * diff[2]) * invEpsilon;

            if (UdD < umin)
            {
                umin = UdD;
            }
            if (UdD > umax)
            {
                umax = UdD;
            }

            if (RdD < rmin)
            {
                rmin = RdD;
            }
            if (RdD > rmax)
            {
                rmax = RdD;
            }
        }
    }
    else
    {
        for (i = 0; i < mNumVertices; i++)
        {
            diff = mWorldVertices[i] - camera->GetPosition();
            vertexCam[1] = Dot(diff, camera->GetUpVector());
            vertexCam[2] = Dot(diff, camera->GetRightVector());

            if (vertexCam[1] < umin)
            {
                umin = vertexCam[1];
            }
            if (vertexCam[1] > umax)
            {
                umax = vertexCam[1];
            }

            if (vertexCam[2] < rmin)
            {
                rmin = vertexCam[2];
            }
            if (vertexCam[2] > rmax)
            {
                rmax = vertexCam[2];
            }
        }
    }

    // Test whether the axis-aligned bounding rectangle is outside the current
    // frustum.  If it is, the adjoining room need not be visited.
    if (frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] >= rmax ||
        frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] <= rmin ||
        frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] >= umax ||
        frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] <= umin)
    {
        return false;
    }

    // The axis-aligned bounding rectangle intersects the current frustum.
    // Reduce the frustum for use in drawing the adjoining room.
    for (int j = 0; j < 6; ++j)
    {
        reducedFrustum[j] = frustum[j];
    }

    if (reducedFrustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] < rmin)
    {
        reducedFrustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] = rmin;
    }

    if (reducedFrustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] > rmax)
    {
        reducedFrustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] = rmax;
    }

    if (reducedFrustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] < umin)
    {
        reducedFrustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] = umin;
    }

    if (reducedFrustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] > umax)
    {
        reducedFrustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] = umax;
    }

    return true;
}

void Rendering::Portal::GetVisibleSet(Culler& culler, bool noCull)
{
    // Visit only the adjacent region if the portal is open.
    if (!Open)
    {
        return;
    }

    // Traverse only through visible portals.
    if (!culler.IsVisible(mNumVertices, mWorldVertices, true))
    {
        return;
    }

    // It is possible that this portal is visited along a path of portals
    // from the current room containing the camera.  Such portals might
    // have a back-facing polygon relative to the camera.  It is not possible
    // to see through these, so cull them.
    const ConstCameraSharedPtr camera = culler.GetCamera();
    if (mWorldPlane.WhichSide(camera->GetPosition()) < Mathematics::NumericalValueSymbol::Zero)
    {
        return;
    }

    // Save the current frustum.
    float saveFrustum[6]{};
    const float* frustum = culler.GetFrustum();
    for (int j = 0; j < 6; ++j)
    {
        saveFrustum[j] = frustum[j];
    }

    // If the observer can see through the portal, the culler's frustum may
    // be reduced in size based on the portal geometry.
    float reducedFrustum[6];
    if (ReducedFrustum(culler, reducedFrustum))
    {
        // Use the reduced frustum for drawing the adjacent region.
        culler.SetFrustum(reducedFrustum);

        // Visit the adjacent region and any nonculled objects in it.
        AdjacentRegion->GetVisibleSet(culler, noCull);

        // Restore the previous frustum.
        culler.SetFrustum(saveFrustum);
    }
}

// Name support.

CoreTools::ObjectSharedPtr Rendering::Portal::GetObjectByName(const std::string& name)
{
    CoreTools::ObjectSharedPtr found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = AdjacentRegion->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    return CoreTools::ObjectSharedPtr();
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::Portal::GetAllObjectsByName(const std::string& name)
{
    std::vector<CoreTools::ObjectSharedPtr> objects = ParentType::GetAllObjectsByName(name);

    std::vector<CoreTools::ObjectSharedPtr> pointerObjects = AdjacentRegion->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::Portal::GetConstObjectByName(const std::string& name) const
{
    CoreTools::ConstObjectSharedPtr found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = AdjacentRegion->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    return CoreTools::ConstObjectSharedPtr();
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::Portal::GetAllConstObjectsByName(const std::string& name) const
{
    std::vector<CoreTools::ConstObjectSharedPtr> objects = ParentType::GetAllConstObjectsByName(name);

    std::vector<CoreTools::ConstObjectSharedPtr> pointerObjects = AdjacentRegion->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    return objects;
}

// Streaming support.

Rendering::Portal::Portal(LoadConstructor value)
    : Object(value), AdjacentRegion(0), Open(false), mNumVertices(0),
      mModelVertices(0), mWorldVertices(0), mModelPlane(0.0f, 0.0f, 0.0f, 0.0f), mWorldPlane(0.0f, 0.0f, 0.0f, 0.0f)
{
}

void Rendering::Portal::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    //source.ReadAggregate(mNumVertices, mModelVertices);
    source.ReadAggregate(mModelPlane);
    Open = source.ReadBool();
    //    source.ReadSharedPtr(AdjacentRegion);

    //    mWorldVertices = NEW1<Mathematics::APointF>(mNumVertices);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Portal::Link(CoreTools::ObjectLink& source)
{
    Object::Link(source);

    //source.ResolveObjectLink(AdjacentRegion);
}

void Rendering::Portal::PostLink()
{
    Object::PostLink();
}

uint64_t Rendering::Portal::Register(CoreTools::ObjectRegister& target) const
{
    if (Object::Register(target))
    {
        // target.Register(AdjacentRegion);
        return true;
    }
    return false;
}

void Rendering::Portal::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    //	target.WriteAggregateWithNumber(mNumVertices, mModelVertices);
    target.WriteAggregate(mModelPlane);
    target.Write(Open);
    //  target.WritePointer(AdjacentRegion);

    // World vertices are computed form model vertices in the update call,
    // so no need to save them.  The world plane is also computed in the
    // update call, so no need to save it.

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Portal::GetStreamingSize() const
{
    int size = Object::GetStreamingSize();
    size += sizeof(mNumVertices);
    size += mNumVertices * sizeof(mModelVertices[0]);
    size += sizeof(mModelPlane);
    size += CORE_TOOLS_STREAM_SIZE(Open);
    size += CORE_TOOLS_STREAM_SIZE(AdjacentRegion);
    return size;
}

#include STSTEM_WARNING_POP