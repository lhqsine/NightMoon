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

#ifndef CORE_NMPREDECLARE_H_
#define CORE_NMPREDECLARE_H_

#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <utility>
#include <functional>

#include "NMTypes.h"
#include "NMDefines.h"
#include "NMEnums.h"
#include "NMMemSTLAlloc.h"
#include "NMMemJEMAlloc.h"
#include "NMMemObjAlloc.h"
#include "NMMemConfig.h"

namespace NightMoon
{
    //////////////////////////////////////////////////////////////////////
    // Smart pointers.
    //////////////////////////////////////////////////////////////////////

    template<typename T>
    struct SharedPtr
    {
        typedef typename std::shared_ptr<T> type;
    };

    template<typename T>
    struct WeakPtr
    {
        typedef typename std::weak_ptr<T> type;
    };

    template<typename T>
    std::shared_ptr<T> MakeSharedPtr()
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T);
#endif
    }

    template<typename T, typename A1>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1));
#endif
    }

    template<typename T, typename A1, typename A2>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5, a6), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5, a6, a7), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5, a6, a7, a8), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5, a6, a7, a8, a9), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9));
#endif
    }

    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
    std::shared_ptr<T> MakeSharedPtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10)
    {
#ifdef NM_STL_USE_ALLOC
        return std::shared_ptr<T>(NM_NEW(T)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10), DefaultDeleter<T>);
#else
        return std::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
#endif
    }

    //////////////////////////////////////////////////////////////////////
    // STL libraries.
    //////////////////////////////////////////////////////////////////////

    template<typename T, typename A = NMMemSTLAlloc<T, NMMemJEMAlloc>>
    struct Vector
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::vector<T, A> type;
        typedef typename std::vector<T, A>::iterator iterator;
        typedef typename std::vector<T, A>::const_iterator const_iterator;
#else
        typedef typename std::vector<T> type;
        typedef typename std::vector<T>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_iterator;
#endif
    };

    template<typename T, typename A = NMMemSTLAlloc<T, NMMemJEMAlloc>>
    struct Queue
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::queue<T, A> type;
        typedef typename std::queue<T, A>::iterator iterator;
        typedef typename std::queue<T, A>::const_iterator const_iterator;
#else
        typedef typename std::queue<T> type;
        typedef typename std::queue<T>::iterator iterator;
        typedef typename std::queue<T>::const_iterator const_iterator;
#endif
    };

    template<typename T, typename P = std::less<T>, typename A = NMMemSTLAlloc<T, NMMemJEMAlloc>>
    struct Set
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::set<T, P, A> type;
        typedef typename std::set<T, P, A>::iterator iterator;
        typedef typename std::set<T, P, A>::const_iterator const_iterator;
#else
        typedef typename std::set<T, P> type;
        typedef typename std::set<T, P>::iterator iterator;
        typedef typename std::set<T, P>::const_iterator const_iterator;
#endif
    };

    template<typename T, typename A = NMMemSTLAlloc<T, NMMemJEMAlloc>>
    struct List
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::list<T, A> type;
        typedef typename std::list<T, A>::iterator iterator;
        typedef typename std::list<T, A>::const_iterator const_iterator;
#else
        typedef typename std::list<T> type;
        typedef typename std::list<T>::iterator iterator;
        typedef typename std::list<T>::const_iterator const_iterator;
#endif
    };

    template<typename K, typename V, typename P = std::less<K>, typename A = NMMemSTLAlloc<std::pair<const K, V>, NMMemJEMAlloc>>
    struct Map
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::map<K, V, P, A> type;
        typedef typename std::map<K, V, P, A>::iterator iterator;
        typedef typename std::map<K, V, P, A>::const_iterator const_iterator;
#else
        typedef typename std::map<K, V, P> type;
        typedef typename std::map<K, V, P>::iterator iterator;
        typedef typename std::map<K, V, P>::const_iterator const_iterator;
#endif
    };

    template<typename K, typename V, typename P = std::less<K>, typename A = NMMemSTLAlloc<std::pair<const K, V>, NMMemJEMAlloc>>
    struct MultiMap
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::multimap<K, V, P, A> type;
        typedef typename std::multimap<K, V, P, A>::iterator iterator;
        typedef typename std::multimap<K, V, P, A>::const_iterator const_iterator;
#else
        typedef typename std::multimap<K, V, P> type;
        typedef typename std::multimap<K, V, P>::iterator iterator;
        typedef typename std::multimap<K, V, P>::const_iterator const_iterator;
#endif
    };

    template<typename K, typename V, typename P = std::less<K>, typename A = NMMemSTLAlloc<std::pair<const K, V>, NMMemJEMAlloc>>
    struct UnorderedMap
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::unordered_map<K, V, P, A> type;
        typedef typename std::unordered_map<K, V, P, A>::iterator iterator;
        typedef typename std::unordered_map<K, V, P, A>::const_iterator const_iterator;
#else
        typedef typename std::unordered_map<K, V, P> type;
        typedef typename std::unordered_map<K, V, P>::iterator iterator;
        typedef typename std::unordered_map<K, V, P>::const_iterator const_iterator;
#endif
    };

    template<typename K, typename V, typename P = std::less<K>, typename A = NMMemSTLAlloc<std::pair<const K, V>, NMMemJEMAlloc>>
    struct UnorderedMultimap
    {
#ifdef NM_STL_USE_ALLOC
        typedef typename std::unordered_multimap<K, V, P, A> type;
        typedef typename std::unordered_multimap<K, V, P, A>::iterator iterator;
        typedef typename std::unordered_multimap<K, V, P, A>::const_iterator const_iterator;
#else
        typedef typename std::unordered_multimap<K, V, P> type;
        typedef typename std::unordered_multimap<K, V, P>::iterator iterator;
        typedef typename std::unordered_multimap<K, V, P>::const_iterator const_iterator;
#endif
    };

    //////////////////////////////////////////////////////////////////////
    // String Utilities
    //////////////////////////////////////////////////////////////////////

#ifdef NM_STL_USE_ALLOC

    typedef std::basic_string<char, std::char_traits<char>, NMMemSTLAlloc<char, NMMemJEMAlloc>>                   String;
    typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, NMMemSTLAlloc<wchar_t, NMMemJEMAlloc>>          WString;
    typedef std::basic_stringstream<char, std::char_traits<char>, NMMemSTLAlloc<char, NMMemJEMAlloc>>             StringStream;
    typedef std::basic_stringstream<wchar_t, std::char_traits<wchar_t>, NMMemSTLAlloc<wchar_t, NMMemJEMAlloc>>    WStringStream;

#define NM_STD_STRING(T) std::basic_string<T, std::char_traits<T>, std::allocator<T> >
#define NM_MEM_STRING(T) std::basic_string<T, std::char_traits<T>, NMMemSTLAlloc<T, NMMemJEMAlloc> >

    template<typename T>
    Bool operator <(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
    }

    template<typename T>
    Bool operator <(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
    }

    template<typename T>
    Bool operator <=(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
    }

    template<typename T>
    Bool operator <=(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
    }

    template<typename T>
    Bool operator >(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
    }

    template<typename T>
    Bool operator >(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
    }

    template<typename T>
    Bool operator >=(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
    }

    template<typename T>
    Bool operator >=(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
    }

    template<typename T>
    Bool operator ==(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
    }

    template<typename T>
    Bool operator ==(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
    }

    template<typename T>
    Bool operator !=(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
    }

    template<typename T>
    Bool operator !=(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
    }

    template<typename T>
    NM_MEM_STRING(T) operator +=(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return NM_MEM_STRING(T)(l) += o.c_str();
    }
    template<typename T>
    NM_MEM_STRING(T) operator +=(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return NM_MEM_STRING(T)(l.c_str()) += o.c_str();
    }

    template<typename T>
    NM_MEM_STRING(T) operator +(const NM_MEM_STRING(T)& l, const NM_STD_STRING(T)& o)
    {
        return NM_MEM_STRING(T)(l) += o.c_str();
    }

    template<typename T>
    NM_MEM_STRING(T) operator +(const NM_STD_STRING(T)& l, const NM_MEM_STRING(T)& o)
    {
        return NM_MEM_STRING(T)(l.c_str()) += o.c_str();
    }

    template<typename T>
    NM_MEM_STRING(T) operator +(const T* l, const NM_MEM_STRING(T)& o)
    {
        return NM_MEM_STRING(T)(l) += o;
    }

#undef NM_STD_STRING
#undef NM_MEM_STRING

#else
    typedef std::string String;
    typedef std::wstring WString;
    typedef std::stringstream StringStream;
    typedef std::wstringstream WStringStream;
#endif
}  // namespace NightMoon
#endif  // CORE_NMPREDECLARE_H_
