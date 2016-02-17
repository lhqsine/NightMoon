/*
-----------------------------------------------------------------
This source file is part of NightMoon

GNU LESSER GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.


This version of the GNU Lesser General Public License incorporates
the terms and conditions of version 3 of the GNU General Public
License, supplemented by the additional permissions listed below.

0. Additional Definitions.

As used herein, "this License" refers to version 3 of the GNU Lesser
General Public License, and the "GNU GPL" refers to version 3 of the GNU
General Public License.

"The Library" refers to a covered work governed by this License,
other than an Application or a Combined Work as defined below.

An "Application" is any work that makes use of an interface provided
by the Library, but which is not otherwise based on the Library.
Defining a subclass of a class defined by the Library is deemed a mode
of using an interface provided by the Library.

A "Combined Work" is a work produced by combining or linking an
Application with the Library.  The particular version of the Library
with which the Combined Work was made is also called the "Linked
Version".

The "Minimal Corresponding Source" for a Combined Work means the
Corresponding Source for the Combined Work, excluding any source code
for portions of the Combined Work that, considered in isolation, are
based on the Application, and not on the Linked Version.

The "Corresponding Application Code" for a Combined Work means the
object code and/or source code for the Application, including any data
and utility programs needed for reproducing the Combined Work from the
Application, but excluding the System Libraries of the Combined Work.

1. Exception to Section 3 of the GNU GPL.

You may convey a covered work under sections 3 and 4 of this License
without being bound by section 3 of the GNU GPL.

2. Conveying Modified Versions.

If you modify a copy of the Library, and, in your modifications, a
facility refers to a function or data to be supplied by an Application
that uses the facility (other than as an argument passed when the
facility is invoked), then you may convey a copy of the modified
version:

a) under this License, provided that you make a good faith effort to
ensure that, in the event an Application does not supply the
function or data, the facility still operates, and performs
whatever part of its purpose remains meaningful, or

b) under the GNU GPL, with none of the additional permissions of
this License applicable to that copy.

3. Object Code Incorporating Material from Library Header Files.

The object code form of an Application may incorporate material from
a header file that is part of the Library.  You may convey such object
code under terms of your choice, provided that, if the incorporated
material is not limited to numerical parameters, data structure
layouts and accessors, or small macros, inline functions and templates
(ten or fewer lines in length), you do both of the following:

a) Give prominent notice with each copy of the object code that the
Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the object code with a copy of the GNU GPL and this license
document.

4. Combined Works.

You may convey a Combined Work under terms of your choice that,
taken together, effectively do not restrict modification of the
portions of the Library contained in the Combined Work and reverse
engineering for debugging such modifications, if you also do each of
the following:

a) Give prominent notice with each copy of the Combined Work that
the Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the Combined Work with a copy of the GNU GPL and this license
document.

c) For a Combined Work that displays copyright notices during
execution, include the copyright notice for the Library among
these notices, as well as a reference directing the user to the
copies of the GNU GPL and this license document.

d) Do one of the following:

0) Convey the Minimal Corresponding Source under the terms of this
License, and the Corresponding Application Code in a form
suitable for, and under terms that permit, the user to
recombine or relink the Application with a modified version of
the Linked Version to produce a modified Combined Work, in the
manner specified by section 6 of the GNU GPL for conveying
Corresponding Source.

1) Use a suitable shared library mechanism for linking with the
Library.  A suitable mechanism is one that (a) uses at run time
a copy of the Library already present on the user's computer
system, and (b) will operate properly with a modified version
of the Library that is interface-compatible with the Linked
Version.

e) Provide Installation Information, but only if you would otherwise
be required to provide such information under section 6 of the
GNU GPL, and only to the extent that such information is
necessary to install and execute a modified version of the
Combined Work produced by recombining or relinking the
Application with a modified version of the Linked Version. (If
you use option 4d0, the Installation Information must accompany
the Minimal Corresponding Source and Corresponding Application
Code. If you use option 4d1, you must provide the Installation
Information in the manner specified by section 6 of the GNU GPL
for conveying Corresponding Source.)

5. Combined Libraries.

You may place library facilities that are a work based on the
Library side by side in a single library together with other library
facilities that are not Applications and are not covered by this
License, and convey such a combined library under terms of your
choice, if you do both of the following:

a) Accompany the combined library with a copy of the same work based
on the Library, uncombined with any other library facilities,
conveyed under the terms of this License.

b) Give prominent notice with the combined library that part of it
is a work based on the Library, and explaining where to find the
accompanying uncombined form of the same work.

6. Revised Versions of the GNU Lesser General Public License.

The Free Software Foundation may publish revised and/or new versions
of the GNU Lesser General Public License from time to time. Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.

Each version is given a distinguishing version number. If the
Library as you received it specifies that a certain numbered version
of the GNU Lesser General Public License "or any later version"
applies to it, you have the option of following the terms and
conditions either of that published version or of any later version
published by the Free Software Foundation. If the Library as you
received it does not specify a version number of the GNU Lesser
General Public License, you may choose any version of the GNU Lesser
General Public License ever published by the Free Software Foundation.

If the Library as you received it specifies that a proxy can decide
whether future versions of the GNU Lesser General Public License shall
apply, that proxy's public statement of acceptance of any version is
permanent authorization for you to choose that version for the
Library.
-----------------------------------------------------------------
*/

#ifndef CORE_NMTRANSFORM_H_
#define CORE_NMTRANSFORM_H_

#include "NMPredeclare.h"
#include "NMComponent.h"
#include "NMVector3.h"
#include "NMQuaternion.h"
#include "NMMatrix4x4.h"

namespace NightMoon
{
    class NMGameObject;
    class NMTransform;

    typedef WeakPtr<NMTransform>::type      NMTransformPtr;
    typedef Vector<NMTransformPtr>::type    NMTransformList;

    enum class ESpace
    {
        World,
        Local,
    };

    class NMTransform NM_FINAL : public NMComponent
    {
        friend NMGameObject;

    public:
        /** Get the parent transform node of this transform, if this transform has no parent, nullptr returned. */
        NMTransformPtr GetParent(void) const;

        /** Get the forward vector of this transform. */
        NMVector3 GetForward(void) const;

        /** Get the right vector of this transform. */
        NMVector3 GetRight(void) const;

        /** Get the up vector of this transform. */
        NMVector3 GetUp(void) const;

        /** Get the rotation by euler angle of this transform. */
        NMVector3 GetEuler(void) const;

        /** Get the local rotation by euler angle of this transform. */
        NMVector3 GetLocalEuler(void) const;

        /** Get local position of this transform. */
        NMVector3 GetLocalPosition(void) const;

        /** Get the local rotation of this transform. */
        NMQuaternion GetLocalRotation(void) const;

        /** Get the local scale of this transform. */
        NMVector3 GetLocalScale(void) const;

        /** Get the world position of this transform. */
        NMVector3 GetWorldPosition(void) const;

        /** Get the world rotation of this transform. */
        NMQuaternion GetWorldRotation(void) const;

        /** Get world scale of this transform. */
        NMVector3 GetWorldScale(void) const;

    public:
        /** Set the parent transform node of this transform. */
        void SetParent(const NMTransformPtr &parent);

        /** Set a new forward vector to this transform. */
        void SetForward(const NMVector3 &fwd);

        /** Set a new right vector to this transform. */
        void SetRight(const NMVector3 &right);

        /** Set a new up vector to this transform. */
        void SetUp(const NMVector3 &up);

        /** Set new rotation by euler angle to this transform. */
        void SetEuler(const NMVector3 &euler);

        /** Set new local rotation by euler angle to this transform. */
        void SetLocalEuler(const NMVector3 &euler);

        /** Set new local position to this transform. */
        void SetLocalPosition(const NMVector3 &localPos);

        /** Set new local rotation of this transform. */
        void SetLocalRotation(const NMQuaternion &rotation);

        /** Set new local scale to this transform. */
        void SetLocalScale(const NMVector3 &localScale);

        /** Set new world position to this transform. */
        void SetWorldPosition(const NMVector3 &worldPos);

        /** Set new world rotation to this transform. */
        void SetWorldRotation(const NMQuaternion &worldPos);

        /** Set new world scale to this transform. */
        void SetWorldScale(const NMVector3 &worldScale);

    public:
        /** Get the local to world matrix from this transform. */
        NMMatrix4x4 GetLocalToWorldMatrix(void) const;

        /** Get the world to local matrix from this transform. */
        NMMatrix4x4 GetWorldToLocalMatrix(void) const;

        /** Get the child transform node by index. */
        NMTransformPtr GetChild(const UInt32 &index) const;

        /** Get the count of the child. */
        UInt32 GetChildCount(void) const;

        // NMTransformPtr FindChild(const String &name) const;

        NMTransformPtr GetRoot(void) const;

        // Bool IsChildOf(const NMTransformPtr &parent);

        /** Rotate this transform to look at the specified target transform. */
        void LookAt(const NMTransformPtr &target);

        /** Rotate this transform to look at the specified target position. */
        void LookAt(const NMVector3 &worldPosition);

        /** Rotate this transform to look at the specified target transform with specified up vector. */
        void LookAt(const NMTransformPtr &target, const NMVector3 &worldUp);

        /** Rotate this transform to look at the specified target position with specified up vector. */
        void LookAt(const NMVector3 &worldPosition, const NMVector3 &worldUp);

        /** Transform point from local space to world space. */
        void TransformPoint(const NMVector3 &point);

        /** Transform point from local space to world space. */
        void TransformPoint(const Float &x, const Float &y, const Float &z);

        /** Transform vector from local space to world space. */
        void TransformVector(const NMVector3 &poin);

        /** Transform vector from local space to world space. */
        void TransformVector(const Float &x, const Float &y, const Float &z);

        /** Transform point from local space to world space, the opposite of TransformPoint. */
        void TransformPointInverse(const NMVector3 &point);

        /** Transform point from local space to world space, the opposite of TransformPoint. */
        void TransformPointInverse(const Float &x, const Float &y, const Float &z);

        /** Transform vector from local space to world space, the opposite of TransformVector. */
        void TransformVectorInverse(const NMVector3 &point);

        /** Transform vector from local space to world space, the opposite of TransformVector. */
        void TransformVectorInverse(const Float &x, const Float &y, const Float &z);

        /** Rotate the transform with specified axis and angle. */
        void Rotate(const NMVector3 &axis, const Float &angle, const ESpace &space);

        /** Rotate the transform with specified euler angle. */
        void Rotate(const NMVector3 &euler, const ESpace &space);

        /** Rotate the transform with specified euler angle. */
        void Rotate(const Float &x, const Float &y, const Float &z, const ESpace &space);

    public:
        /** Default constructor. */
        NMTransform(void);

    private:
        /** Default constructor, invalid operation. */
        NMTransform(const NMTransform& src);

        /** Copy operation. */
        void operator=(const NMTransform& src);

        /** Calculate the transform matrix by the positions, rotations and scales from this
            transform and parents. Can only be called by GameObject::_UpdateTransform. */
        void _UpdateTransform(void);

    private:
        /** The parents of this transform node. */
        NMTransformPtr mParent;

        /** Cached parents of this transform in deep. */
        NMTransformList mParents;

        /** The children node of this transform node. */
        NMTransformList mChildren;

        /** The local position of this transform node. */
        NMVector3 mLocalPosition;

        /** The local rotation of this transform node. */
        NMQuaternion mLocalRotation;

        /** The local scale of this transform node. */
        NMVector3 mLocalScale;

        /** The world position of this transform node. */
        NMVector3 mWorldPosition;

        /** The world rotation of this transform node. */
        NMQuaternion mWorldRotation;

        /** The world scale of this transform node. */
        NMVector3 mWorldScale;

        /** The matrix of world transform. */
        NMMatrix4x4 mWorldTransform;
    };
}  // namespace NightMoon
#endif  // CORE_NMTRANSFORM_H_
