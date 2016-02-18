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

#include <limits>
#include <algorithm>
#include "NMQuaternion.h"
#include "NMMatrix4x4.h"

namespace NightMoon
{
    //-----------------------------------------------------------------
    const NMQuaternion NMQuaternion::zero = NMQuaternion(0.0f, 0.0f, 0.0f, 0.0f);
    //-----------------------------------------------------------------
    const NMQuaternion NMQuaternion::identity = NMQuaternion(0.0f, 0.0f, 0.0f, 1.0f);
    //-----------------------------------------------------------------
    NMQuaternion::NMQuaternion(void)
        :x(0), y(0), z(0), w(1.0f)
    {
    }
    //-----------------------------------------------------------------
    NMQuaternion::NMQuaternion(const Float &fx, const Float &fy, const Float &fz, const Float &fw)
        : x(fx), y(fy), z(fz), w(fw)
    {
    }
    //-----------------------------------------------------------------
    NMQuaternion::NMQuaternion(const NMQuaternion& src)
        : x(src.x), y(src.y), z(src.z), w(src.w)
    {
    }
    //-----------------------------------------------------------------
    NMQuaternion& NMQuaternion::operator = (const NMQuaternion &q)
    {
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
        this->w = q.w;

        return (*this);
    }
    //-----------------------------------------------------------------
    Bool NMQuaternion::operator == (const NMQuaternion &q)
    {
        return (this->x == q.x &&
            this->y == q.y &&
            this->z == q.z &&
            this->w == q.w);
    }
    //-----------------------------------------------------------------
    Bool NMQuaternion::operator != (const NMQuaternion &q)
    {
        return (this->x != q.x ||
            this->y != q.y ||
            this->z != q.z ||
            this->w != q.w);
    }
    //-----------------------------------------------------------------
    const NMQuaternion NMQuaternion::operator + () const
    {
        return (*this);
    }
    //-----------------------------------------------------------------
    const NMQuaternion NMQuaternion::operator - () const
    {
        return NMQuaternion(-this->x, -this->y, -this->z, -this->w);
    }
    //-----------------------------------------------------------------
    NMVector3 operator * (const NMQuaternion &q, const NMVector3 &v)
    {
        // Nvidia SDK implementation
        NMVector3 uv, uuv;
        NMVector3 qvec(q.x, q.y, q.z);

        uv = NMVector3::Cross(qvec, v);
        uuv = NMVector3::Cross(qvec, uv);

        uv *= (2.0f * q.w);
        uuv *= 2.0f;

        return v + uv + uuv;
    }
    //-----------------------------------------------------------------
    NMQuaternion operator + (const NMQuaternion &q, const Float &val)
    {
        return NMQuaternion(q.x + val, q.y + val, q.z + val, q.w + val);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator + (const Float &val, const NMQuaternion &q)
    {
        return NMQuaternion(val + q.x, val + q.y, val + q.z, val + q.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator + (const NMQuaternion &lhs, const NMQuaternion &rhs)
    {
        return NMQuaternion(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator - (const NMQuaternion &q, const Float &val)
    {
        return NMQuaternion(q.x - val, q.y - val, q.z - val, q.w - val);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator - (const Float &val, const NMQuaternion &q)
    {
        return NMQuaternion(val - q.x, val - q.y, val - q.z, val - q.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator - (const NMQuaternion &lhs, const NMQuaternion &rhs)
    {
        return NMQuaternion(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator * (const NMQuaternion &q, const Float &val)
    {
        return NMQuaternion(q.x *val, q.y * val, q.z * val, q.w * val);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator * (const Float &val, const NMQuaternion &q)
    {
        return NMQuaternion(q.x *val, q.y * val, q.z * val, q.w * val);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator * (const NMQuaternion &lhs, const NMQuaternion &rhs)
    {
        return NMQuaternion(
            rhs[3] * lhs[0] + rhs[0] * lhs[3] + rhs[1] * lhs[2] - rhs[2] * lhs[1],
            rhs[3] * lhs[1] - rhs[0] * lhs[2] + rhs[1] * lhs[3] + rhs[2] * lhs[0],
            rhs[3] * lhs[2] + rhs[0] * lhs[1] - rhs[1] * lhs[0] + rhs[2] * lhs[3],
            rhs[3] * lhs[3] - rhs[0] * lhs[0] - rhs[1] * lhs[1] - rhs[2] * lhs[2]);
    }
    //-----------------------------------------------------------------
    NMQuaternion& NMQuaternion::operator *= (const NMQuaternion &rhs)
    {
        this->data[0] = rhs[3] * this->data[0] + rhs[0] * this->data[3] + rhs[1] * this->data[2] - rhs[2] * this->data[1];
        this->data[1] = rhs[3] * this->data[1] - rhs[0] * this->data[2] + rhs[1] * this->data[3] + rhs[2] * this->data[0];
        this->data[2] = rhs[3] * this->data[2] + rhs[0] * this->data[1] - rhs[1] * this->data[0] + rhs[2] * this->data[3];
        this->data[3] = rhs[3] * this->data[3] - rhs[0] * this->data[0] - rhs[1] * this->data[1] - rhs[2] * this->data[2];

        return (*this);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator / (const NMQuaternion &q, const Float &val)
    {
        return NMQuaternion(q.x / val, q.y / val, q.z / val, q.w / val);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator / (const Float &val, const NMQuaternion &q)
    {
        return NMQuaternion(val / q.x, val / q.y, val / q.z, val / q.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion operator / (const NMQuaternion &lhs, const NMQuaternion &rhs)
    {
        return lhs * NMQuaternion::Inverse(rhs);
    }
    //-----------------------------------------------------------------
    Float NMQuaternion::operator[] (const size_t &index) const
    {
        NM_ASSERT_MSG(index < 4, "[Assert] Out of range.");
        return data[index];
    }
    //-----------------------------------------------------------------
    Float& NMQuaternion::operator[] (const size_t &index)
    {
        NM_ASSERT_MSG(index < 4, "[Assert] Out of range.");
        return data[index];
    }
    //-----------------------------------------------------------------
    Float NMQuaternion::Angle(const NMQuaternion &a, const NMQuaternion &b)
    {
        Float f = NMQuaternion::Dot(a, b);
        return acos(std::min(abs(f), 1.0f)) * 2.0f * 57.29578f;
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::AxisAngle(const Float &angle, const Float &x, const Float &y, const Float &z)
    {
        NMQuaternion q = NMQuaternion::identity;

        // @TODO eranzhao
        NM_ASSERT_MSG(false, "Not Implement yet.");
        return q;
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::AxisAngle(const Float &angle, const NMVector3 &axis)
    {
        return NMQuaternion::AxisAngle(angle, axis.x, axis.y, axis.z);
    }
    //-----------------------------------------------------------------
    Float NMQuaternion::Dot(const NMQuaternion &a, const NMQuaternion &b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::EulerAngle(const Float &x, const Float &y, const Float &z)
    {
        return NMQuaternion(
            cos(x / 2.0f) * cos(y / 2.0f) * cos(z / 2.0f) + sin(x / 2.0f) * sin(y / 2.0f) * sin(z / 2.0f),
            sin(x / 2.0f) * cos(y / 2.0f) * cos(z / 2.0f) - cos(x / 2.0f) * sin(y / 2.0f) * sin(z / 2.0f),
            cos(x / 2.0f) * sin(y / 2.0f) * cos(z / 2.0f) + sin(x / 2.0f) * cos(y / 2.0f) * sin(z / 2.0f),
            cos(x / 2.0f) * cos(y / 2.0f) * sin(z / 2.0f) - sin(x / 2.0f) * sin(y / 2.0f) * cos(z / 2.0f));
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::EulerAngle(const NMVector3 &euler)
    {
        return NMQuaternion::EulerAngle(euler.x, euler.y, euler.z);
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::FromToRotation(const NMVector3 &from, const NMVector3 &to)
    {
        NMQuaternion q = NMQuaternion::identity;

        // @TODO eranzhao
        NM_ASSERT_MSG(false, "Not Implement yet.");
        return q;
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::Conjugate(const NMQuaternion &q)
    {
        return NMQuaternion(-q.x, -q.y, -q.z, q.w);
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::Inverse(const NMQuaternion &rotation)
    {
        // Multiplicative inverse method: q ^(-1) = q^*/(q.q^*)
        return NMQuaternion::Conjugate(rotation) / NMQuaternion::SqrLength(rotation);
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::SLerp(const NMQuaternion &from, const NMQuaternion &to, const Float &t)
    {
        NMQuaternion q = NMQuaternion::identity;

        // @TODO eranzhao
        NM_ASSERT_MSG(false, "Not Implement yet.");
        return q;
    }
    //-----------------------------------------------------------------
    NMQuaternion NMQuaternion::FromRotationMatrix(const NMMatrix4x4 &m)
    {
        NMQuaternion q = NMQuaternion::identity;

        // @TODO eranzhao
        NM_ASSERT_MSG(false, "Not Implement yet.");
        return q;
    }
    //-----------------------------------------------------------------
    Float NMQuaternion::Length(const NMQuaternion &q)
    {
        return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    }
    //-----------------------------------------------------------------
    Float NMQuaternion::SqrLength(const NMQuaternion &q)
    {
        return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    }
    //-----------------------------------------------------------------
    NMMatrix4x4 NMQuaternion::ToRotationMatrix(const NMQuaternion &q)
    {
        NMMatrix4x4 mat = NMMatrix4x4::identity;

        // @TODO eranzhao
        NM_ASSERT_MSG(false, "Not Implement yet.");
        return mat;
    }
    //-----------------------------------------------------------------
}  // namespace NightMoon
