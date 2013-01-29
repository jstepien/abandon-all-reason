Abandon All Reason
==================

A header-only, type-level, template metaprogramming extravaganza, in which your
compiler performs primality test and other things it was definitely not designed
for.
[![Build Status](https://secure.travis-ci.org/jstepien/abandon-all-reason.png?branch=master)](http://travis-ci.org/jstepien/abandon-all-reason)

Principal premise
-----------------

> _Just because you can doesn't mean you should._

Usage
-----

The header with the implementation should compile fine on any decent and
relatively tolerant compiler. There are no external dependencies.

Run tests using `make`. In order to build them your compiler has to speak C++11
and you should have Boost nearby.

Related work
------------

In contrast to what was proposed in [_C++ Template Metaprogramming_][cpp-t-mp],
this project does not parametrise its templates with integer values but with
integers expressed in the type-level. To put it differently, it's insane.

[cpp-t-mp]: http://aszt.inf.elte.hu/~gsd/halado_cpp/ch06s04.html#Static-metaprogramming

Copyrights
----------

Copyright (c) 2013 Jan Stępień

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
