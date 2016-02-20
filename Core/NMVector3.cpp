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

#include "NMMathLib.h"
#include "NMVector3.h"

namespace NightMoon
{
    //-----------------------------------------------------------------
    const NMVector3 NMVector3::zero = NMVector3(0, 0, 0);
    const NMVector3 NMVector3::one = NMVector3(1.0f, 1.0f, 1.0f);
    const NMVector3 NMVector3::forward = NMVector3(0.0f, 0.0f, 1.0f);
    const NMVector3 NMVector3::back = NMVector3(0.0f, 0.0f, -1.0f);
    const NMVector3 NMVector3::up = NMVector3(0.0f, 1.0f, 0.0f);
    const NMVector3 NMVector3::down = NMVector3(0.0f, -1.0f, 0.0f);
    const NMVector3 NMVector3::left = NMVector3(-1.0f, 0.0f, 0.0f);
    const NMVector3 NMVector3::right = NMVector3(1.0f, 0.0f, 0.0f);
    //-----------------------------------------------------------------
    NMVector3::NMVector3(void)
        :x(0), y(0), z(0)
    {
    }
    //-----------------------------------------------------------------
    NMVector3::NMVector3(const Float &fx, const Float &fy, const Float &fz)
        : x(fx), y(fy), z(fz)
    {
    }
    //-----------------------------------------------------------------
    NMVector3::NMVector3(const Float &val)
        : x(val), y(val), z(val)
    {
    }
    //-----------------------------------------------------------------
    NMVector3::NMVector3(const NMVector3 &src)
        : x(src.x), y(src.y), z(src.z)
    {
    }
    //-----------------------------------------------------------------
    Float NMVector3::operator[] (const size_t &index) const
    {
        NM_ASSERT_MSG(index < 3, "[Assert] Out of range.");
        return this->data[index];
    }
    //-----------------------------------------------------------------
    Float& NMVector3::operator[] (const size_t &index)
    {
        NM_ASSERT_MSG(index < 3, "[Assert] Out of range.");
        return this->data[index];
    }
    //-----------------------------------------------------------------
    NMVector3& NMVector3::operator= (const NMVector3 &rhs)
    {
        std::memcpy(this->data, rhs.data, sizeof(Float)* 3);
        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3& NMVector3::operator= (const Float &rhs)
    {
        this->x = rhs;
        this->y = rhs;
        this->z = rhs;

        return (*this);
    }
    //-----------------------------------------------------------------
    Bool NMVector3::operator == (const NMVector3 &rhs) const
    {
        return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
    }
    //-----------------------------------------------------------------
    Bool NMVector3::operator != (const NMVector3 &rhs) const
    {
        return (this->x != rhs.x || this->y != rhs.y || this->z != rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator + (const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator - (const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator * (const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator * (const Float &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator * (const NMVector3 &lhs, const Float &rhs)
    {
        return NMVector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }
    //-----------------------------------------------------------------
    NMVector3 operator / (const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator / (const Float &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
    }
    //-----------------------------------------------------------------
    NMVector3 operator / (const NMVector3 &lhs, const Float &rhs)
    {
        return NMVector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    }
    //-----------------------------------------------------------------
    const NMVector3 NMVector3::operator + (void) const
    {
        return (*this);
    }
    //-----------------------------------------------------------------
    const NMVector3 NMVector3::operator - (void) const
    {
        return NMVector3(-x, -y, -z);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator += (const NMVector3 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator -= (const NMVector3 &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator *= (const NMVector3 &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;

        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator *= (const Float &rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator /= (const NMVector3 &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;

        return (*this);
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::operator /= (const Float &rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;

        return (*this);
    }
    //-----------------------------------------------------------------
    Bool NMVector3::IsNan(const NMVector3 &v)
    {
        return NMMathLib::IsNan(v.x) || NMMathLib::IsNan(v.y) || NMMathLib::IsNan(v.z);
    }
    //-----------------------------------------------------------------
    Float NMVector3::AngleBetween(const NMVector3 &from, const NMVector3 &to)
    {
        return NMMathLib::Acos(NMMathLib::Clamp(NMVector3::Dot(NMVector3::Normalize(from), NMVector3::Normalize(to)), -1.0f, 1.0f)) * NMMathLib::Rad2Deg;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Cross(const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
    }
    //-----------------------------------------------------------------
    Float NMVector3::Distance(const NMVector3 &a, const NMVector3 &b)
    {
        NMVector3 dist = NMVector3(a.x - b.x, a.y - b.y, a.z - b.z);
        return NMMathLib::Sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
    }
    //-----------------------------------------------------------------
    Float NMVector3::Dot(const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Lerp(const NMVector3 &from, const NMVector3 &to, const Float &t)
    {
        Float tmp = NMMathLib::Clamp(t, 0.0f, 1.0f);
        return from + (to - from) * tmp;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Max(const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(NMMathLib::Max(lhs.x, rhs.x), NMMathLib::Max(lhs.y, rhs.y), NMMathLib::Max(lhs.z, rhs.z));
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Min(const NMVector3 &lhs, const NMVector3 &rhs)
    {
        return NMVector3(NMMathLib::Min(lhs.x, rhs.x), NMMathLib::Min(lhs.y, rhs.y), NMMathLib::Min(lhs.z, rhs.z));
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::MoveTowards(const NMVector3 &curr, const NMVector3 &target, const Float &max_dist_delta)
    {
        NMVector3 a = target - curr;
        Float magnitude = NMVector3::Length(a);
        return (magnitude <= max_dist_delta || magnitude == 0.0f) ? target : curr + a / magnitude * max_dist_delta;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Normalize(const NMVector3 &src)
    {
        Float num = NMVector3::Length(src);
        // return num > 1E-05f ? src / num : NMVector3::zero;
        return num > NMMathLib::Epsilon ? src / num : NMVector3::zero;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Project(const NMVector3 &v, const NMVector3 &on_normal)
    {
        Float num = NMVector3::Dot(on_normal, on_normal);
        // return (num < 1.401298E-45f) ? NMVector3::zero : on_normal * NMVector3::Dot(v, on_normal) / num;
        return (num < NMMathLib::Epsilon) ? NMVector3::zero : on_normal * NMVector3::Dot(v, on_normal) / num;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Reflect(const NMVector3 &in_dir, const NMVector3 &in_normal)
    {
        return in_normal  * (-2.0f * NMVector3::Dot(in_normal, in_dir)) + in_dir;
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::Scale(const NMVector3 &a, const NMVector3 &b)
    {
        return NMVector3(a.x * b.x, a.y * b.y, a.z * b.z);
    }
    //-----------------------------------------------------------------
    Float NMVector3::SqrLength(const NMVector3 &v)
    {
        return NMVector3::Dot(v, v);
    }
    //-----------------------------------------------------------------
    Float NMVector3::Length(const NMVector3 &v)
    {
        return NMMathLib::Sqrt(NMVector3::Dot(v, v));
    }
    //-----------------------------------------------------------------
    NMVector3 NMVector3::ClampLength(const NMVector3 &v, const Float &max_len)
    {
        return NMVector3::SqrLength(v) > max_len * max_len ? NMVector3::Normalize(v) * max_len : v;
    }
    //-----------------------------------------------------------------
}  // namespace NightMoon
