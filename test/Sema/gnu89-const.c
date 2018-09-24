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
CHECK-C89: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C89-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C99: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C99-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C11: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C11-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C17: 21:7: warning: duplicate 'const' declaration specifier
CHECK-C17-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier

CHECK-GNU89: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU89-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU99: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU99-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU11: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU11-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU17: 21:7: warning: duplicate 'const' declaration specifier
CHECK-GNU17-PEDANTIC: 21:7: warning: duplicate 'const' declaration specifier
*/

typedef const int t;
const t c_i2;
/*
CHECK-C89-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C89-PEDANTIC: 43:1: warning: duplicate 'const' declaration specifier
          ^ NOTE: special case
CHECK-C99-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C99-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C11-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C11-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C17-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-C17-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier

CHECK-GNU89-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU89-PEDANTIC: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU99-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU99-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU11-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU11-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU17-NOT: 43:1: warning: duplicate 'const' declaration specifier
CHECK-CNU17-PEDANTIC-NOT: 43:1: warning: duplicate 'const' declaration specifier
*/

const int c_i3;
const typeof(c_i) c_i4;
/*
CHECK-C89: 66:19: error: expected function body after function declarator
CHECK-C89-PEDANTIC: 66:19: error: expected function body after function declarator
CHECK-C99: 66:19: error: expected function body after function declarator
CHECK-C99-PEDANTIC: 66:19: error: expected function body after function declarator
CHECK-C11: 66:19: error: expected function body after function declarator
CHECK-C11-PEDANTIC: 66:19: error: expected function body after function declarator
CHECK-C17: 66:19: error: expected function body after function declarator
CHECK-C17-PEDANTIC: 66:19: error: expected function body after function declarator

CHECK-GNU89-NOT: 66:1: warning: duplicate 'const' declaration specifier
            ^ NOTE: special case
CHECK-GNU89-PEDANTIC: 66:1: warning: duplicate 'const' declaration specifier
            ^ NOTE: special case
CHECK-GNU99-NOT: 66:1: warning: duplicate 'const' declaration specifier
CHECK-GNU99-PEDANTIC-NOT: 66:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-NOT: 66:1: warning: duplicate 'const' declaration specifier
CHECK-GNU11-PEDANTIC-NOT: 66:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-NOT: 66:1: warning: duplicate 'const' declaration specifier
CHECK-GNU17-PEDANTIC-NOT: 66:1: warning: duplicate 'const' declaration specifier
*/
