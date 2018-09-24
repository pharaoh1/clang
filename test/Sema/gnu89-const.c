/*
RUN: not %clang_cc1 %s -std=c89 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C89 %s
RUN: not %clang_cc1 %s -std=c89 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C89-PEDANTIC %s
RUN: not %clang_cc1 %s -std=c99 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C99 %s
RUN: not %clang_cc1 %s -std=c99 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C99-PEDANTIC %s
RUN: not %clang_cc1 %s -std=c11 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C11 %s
RUN: not %clang_cc1 %s -std=c11 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C11-PEDANTIC %s
RUN: not %clang_cc1 %s -std=c17 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C17 %s
RUN: not %clang_cc1 %s -std=c17 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-C17-PEDANTIC %s

RUN: %clang_cc1 %s -std=gnu89 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU89 %s
RUN: %clang_cc1 %s -std=gnu89 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU89-PEDANTIC %s
RUN: %clang_cc1 %s -std=gnu99 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU99 %s
RUN: %clang_cc1 %s -std=gnu99 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU99-PEDANTIC %s
RUN: %clang_cc1 %s -std=gnu11 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU11 %s
RUN: %clang_cc1 %s -std=gnu11 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU11-PEDANTIC %s
RUN: %clang_cc1 %s -std=gnu17 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU17 %s
RUN: %clang_cc1 %s -std=gnu17 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU17-PEDANTIC %s
*/

const const int c_i;
/*
CHECK: 21:7: warning: duplicate 'const' declaration specifier
*/

typedef const int t;
const t c_i2;
/*
CHECK-C89-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C89-PEDANTIC: 27:1: warning: duplicate 'const' declaration specifier
          ^ NOTE: special case
CHECK-C99-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C99-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C11-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C11-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C17-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-C17-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier

CHECK-GNU89-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU89-PEDANTIC: 27:1: warning: duplicate 'const' declaration specifier
            ^ NOTE: special case
CHECK-GNU99-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU99-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-NOT: 27:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-PEDANTIC-NOT: 27:1: warning: duplicate 'const' declaration specifier
*/

const int c_i3;
const typeof(c_i) c_i4;
/*
CHECK-C89: 51:19: error: expected function body after function declarator
CHECK-C89-PEDANTIC: 51:19: error: expected function body after function declarator
CHECK-C99: 51:19: error: expected function body after function declarator
CHECK-C99-PEDANTIC: 51:19: error: expected function body after function declarator
CHECK-C11: 51:19: error: expected function body after function declarator
CHECK-C11-PEDANTIC: 51:19: error: expected function body after function declarator
CHECK-C17: 51:19: error: expected function body after function declarator
CHECK-C17-PEDANTIC: 51:19: error: expected function body after function declarator

CHECK-GNU89-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU89-PEDANTIC: 51:1: warning: duplicate 'const' declaration specifier
            ^ NOTE: special case
CHECK-GNU99-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU99-PEDANTIC-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-PEDANTIC-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-NOT: 51:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-PEDANTIC-NOT: 51:1: warning: duplicate 'const' declaration specifier
*/
