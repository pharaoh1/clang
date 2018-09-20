// RUN: %clang_cc1 %s -std=gnu89 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu89 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-GNU89-PEDANTIC %s
// RUN: %clang_cc1 %s -std=gnu99 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu99 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu11 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu11 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu17 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s
// RUN: %clang_cc1 %s -std=gnu17 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s

// Do not warn about duplicate const declaration specifier as the result of
// typeof in gnu89, unless -pedantic was specified. Do not warn in gnu99+, even
// with -pedantic.
const int c_i;
const typeof(c_i) c_i2;
// CHECK-GNU89-PEDANTIC: 14:7: warning: extension used
// CHECK-GNU89-PEDANTIC: 14:1: warning: duplicate 'const' declaration specifier
// CHECK-ABSTRUSE-NOT: 14:1: warning: duplicate 'const' declaration specifier

const const int c_i3;
// CHECK: 19:7: warning: duplicate 'const' declaration specifier

typedef const int t;
const t c_i4;
// CHECK: 23:1: warning: duplicate 'const' declaration specifier
